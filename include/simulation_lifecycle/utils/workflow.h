#ifndef __SIMULATION_LIFECYCLE_WORKFLOW_H__
#define __SIMULATION_LIFECYCLE_WORKFLOW_H__

#include <unistd.h>
#include <cJSON.h>


/**
 * @brief Reads workflow.json file.
 * @param[in] path_to_file path to the file to be loaded.
 * @return cJSON object containing workflow.
 */
cJSON * read_workflow_file(char *path_to_file);

/**
 * @brief Reads the output folder from a workflow.json file.
 * @param[in] workflow cJSON workflow from read_workflow_file().
 * @return a string containing the output folder path.
 */
char * read_output_folder(const cJSON *const workflow);

/**
 * @brief Reads data_sources object from workflow.
 * @param[in] workflow cJSON workflow from read_workflow_file().
 * @return cJSON object containing the data_sources object.
 */
cJSON * read_data_sources(const cJSON *workflow);

/**
 * @brief Reads simulation object from workflow.
 * @param[in] workflow cJSON workflow from read_workflow_file().
 * @return cJSON object containing the simulation object.
 */
cJSON * read_simulation(const cJSON *workflow);

/**
 * @brief Reads spatial analysis object from workflow.
 * @param[in] workflow cJSON workflow from read_workflow_file().
 * @return cJSON object containing the spatial analysis object.
 */
cJSON * read_spatial_analysis(const cJSON *workflow);

/**
 * @brief Reads conversion object from workflow.
 * @param[in] workflow cJSON workflow from read_workflow_file().
 * @return cJSON object containing the conversion object.
 */
cJSON * read_conversion(const cJSON *workflow);

/**
 * @brief Reads visualization object from workflow.
 * @param[in] workflow cJSON workflow from read_workflow_file().
 * @return cJSON object containing the visualization object.
 */
cJSON * read_visualization(const cJSON *workflow);

/**
 * @brief Validates the cJSON workflow object.
 * @param[in] workflow cJSON workflow from read_workflow_file().
 * @return 0 if successful, error code otherwise.
 */
int validate_workflow(const cJSON *workflow);

/**
 * @brief Checks if workflow provided by the user uses any data sources.
 * @param[in] workflow cJSON workflow from read_workflow_file().
 * @return 1 if data sources are needed, 0 otherwise.
 */
int data_sources_required(const cJSON *const workflow);

/**
 * @brief Checks if workflow provided by the user uses any spatial analysis function.
 * @param[in] workflow cJSON workflow from read_workflow_file().
 * @return 1 if spatial analysis is needed, 0 otherwise.
 */
 int spatial_analysis_required(const cJSON *workflow);

/**
* @brief Checks if workflow provided by the user uses the build simulation scenario tool.
* @param[in] workflow cJSON workflow from read_workflow_file().
* @return 1 if build simulation scenario is needed, 0 otherwise.
*/
int build_sim_scenario_required(const cJSON *workflow);

/**
* @brief Checks if workflow provided by the user wants to run a simulation.
* @param[in] workflow cJSON workflow from read_workflow_file().
* @return 1 if run simulation is needed, 0 otherwise.
*/
int run_sim_required(const cJSON *workflow);

/**
* @brief Checks if workflow provided by the user wants to convert files.
* @param[in] workflow cJSON workflow from read_workflow_file().
* @return 1 if create visualization is needed, 0 otherwise.
*/
int conversion_required(const cJSON *workflow);

/**
* @brief Checks if workflow provided by the user wants to create visualization files.
* @param[in] workflow cJSON workflow from read_workflow_file().
* @return 1 if create visualization is needed, 0 otherwise.
*/
int create_viz_required(const cJSON *workflow);

#endif //__SIMULATION_LIFECYCLE_WORKFLOW_H__
