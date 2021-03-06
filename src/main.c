#include <stdio.h>
#include <cJSON.h>
#include <sys/stat.h>
#include "simulation_lifecycle/utils/linked_list.h"
#include "simulation_lifecycle/utils/workflow.h"
#include "simulation_lifecycle/spatial_analysis.h"
#include "simulation_lifecycle/simulation.h"
#include "simulation_lifecycle/convert.h"
#include "simulation_lifecycle/visualization.h"

/**
 * Simulation Lifecycle: main function.
 * @param argc number of arguments.
 * @param argv value of the arguments.
 * @return 0 if flow ran successfully.  TODO better documentation
 */
int main(int argc, char *argv[]) {
    fprintf(stdout, "Reading input parameters... ");
    if (argc != 2) {
        fprintf(stderr, "Wrong number of arguments.\n");
        return -1;
    }
    fprintf(stdout, "Ok.\n");

    fprintf(stdout, "Reading workflow file... ");
    cJSON *workflow = read_workflow_file(argv[1]);
    fprintf(stdout, "Ok.\n");

    fprintf(stdout, "Validating workflow file... ");
    int res = validate_workflow(workflow);

    if (res) {
        fprintf(stderr, "Workflow is invalid.\n");
        goto main_end;
    }
    fprintf(stdout, "Ok.\n");

    char * output = read_output_folder(workflow);
    mkdir(output, 0777);

    node_t *data_sources = NULL;

    fprintf(stdout, "Reading in data sources... ");
    if (data_sources_required(workflow)) {
        res = read_data_in(workflow, &data_sources);

        if (res != SUCCESS) {
            fprintf(stderr, "Build simulation scenario failed. Error code: %d\n", res);
            goto main_end;
        }
    }
    fprintf(stdout, "Ok.\n");

    fprintf(stdout, "Executing spatial analysis operations... ");
    if (spatial_analysis_required(workflow)) {
        // fprintf(stderr, "Spatial analysis is not currently available. Skipping this part.\n"); // TODO
        register_operations();

        execute_workflow(workflow, &data_sources);
    }
    fprintf(stdout, "Ok.\n");

    fprintf(stdout, "Building simulation scenario... ");
    if (build_sim_scenario_required(workflow)) {
        if ((res = build_simulation_scenario(read_simulation(workflow), &data_sources, output))) {
            fprintf(stderr, "Build simulation scenario failed. Error code: %d\n", res);
            fprintf(stderr, "Hint: did you remove the output file of a previous scenario building?\n");
            goto main_end;
        }
    }
    fprintf(stdout, "Ok.\n");

    fprintf(stdout, "Running Cadmium Irregular Cell-DEVS simulation... ");
    if (run_sim_required(workflow)) {
        if ((res = run_sim(read_simulation(workflow), output))) {
            fprintf(stderr, "Run simulation failed. Error code: %d\n", res);
            fprintf(stderr, "Hint: did you remove the output file of a previous simulation?\n");
            goto main_end;
        }
    }
    fprintf(stdout, "Ok.\n");

    fprintf(stdout, "Converting simulation results to WebViewer format... ");
    if (conversion_required(workflow)) {
        cJSON * conv = read_conversion(workflow);
        if ((res = convert_results(output, conv))) {
            fprintf(stderr, "Unable to convert results. Error code: %d\n", res);
            goto main_end;
        }
    }
    fprintf(stdout, "Ok.\n");

    fprintf(stdout, "Preparing visualization for WebViewer... ");
    // if (create_viz_required(workflow, output)) {
    if (create_viz_required(workflow)) {
        cJSON * viz = read_visualization(workflow);

        if ((res = validate_visualization(viz))) {
            fprintf(stderr, "Visualization configuration is invalid. Error code: %d\n", res);
            goto main_end;
        }

        if ((res = package_visualization(viz, output))) {
            fprintf(stderr, "Unable to convert results. Error code: %d\n", res);
            goto main_end;
        }
    }
    fprintf(stdout, "Ok.\n");

main_end:  /* We use label to return error code and clean the workflow object TODO anything else? */
    if (workflow != NULL) {
        cJSON_Delete(workflow);
    }

    fprintf(stdout, "All done.");

    return res;
}
