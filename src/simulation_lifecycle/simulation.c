#include <stdio.h>
#include <string.h>
#include "cJSON.h"
#include "simulation_lifecycle/error.h"
#include "simulation_lifecycle/utils/file.h"
#include "simulation_lifecycle/structures.h"
#include "simulation_lifecycle/simulation.h"

#define MODEL_SIR "sir"
#define MODEL_SIRS "sirs"
#define MODEL_SIRD "sird"
#define MODEL_SIRDS "sirds"

int model_exists(const char *model) {
    if (strcmp(MODEL_SIR, model) == 0) {
        return 1;
    } else if (strcmp(MODEL_SIRS, model) == 0) {
        return 1;
    } else if (strcmp(MODEL_SIRD, model) == 0) {
        return 1;
    } else if (strcmp(MODEL_SIRDS, model) == 0) {
        return 1;
    } else {
        return 0;
    }
}

int check_sim_preconditions(const cJSON *simulation_config,
                            const feature_set_t *p_features, const relation_set_t *p_relations) {
    cJSON *model_name = cJSON_GetObjectItemCaseSensitive(simulation_config, "model_id");
    if (model_name == NULL) {
        return MODEL_EMPTY;
    } else if (!(cJSON_IsString(model_name) && model_exists(model_name->valuestring))) {
        return MODEL_NOT_FOUND;
    }
    /*
    if (p_features == NULL || feature_set_empty(p_features)) {
        return FEATURE_SET_EMPTY;
    }
    if (p_relations == NULL || relation_set_empty(p_relations)) {
        return RELATION_SET_EMPTY;
    }
    if (inconsistent_data(p_features, p_relations)) {
        return INCONSISTENT_DATA;
    }
    */
    cJSON *output_path = cJSON_GetObjectItemCaseSensitive(simulation_config, "output_path");
    if (output_path == NULL || !cJSON_IsString(output_path) || *output_path->valuestring == '\0') {
        return OUTPUT_PATH_EMPTY;
    } else if (file_exists(output_path->valuestring)) {
        return OUTPUT_FILE_EXISTS;
    }
    return SUCCESS;
}

int build_simulation_scenario(cJSON *simulation_config, feature_set_t *p_features, relation_set_t *p_relations) {
    int res = check_sim_preconditions(simulation_config, p_features, p_relations);
    if (res) {
        return res;
    }
    // TODO
    char *string = NULL;
    cJSON *root = cJSON_CreateObject();
    cJSON *def_config = cJSON_CreateObject();

    cJSON_AddItemToObject(root, "default", def_config);

    /* Create string from result and remove cJSON structures */
    string = cJSON_Print(root);
    cJSON_Delete(root);
    return 0;
    // return write_data_to_file(output_path, string);
}
