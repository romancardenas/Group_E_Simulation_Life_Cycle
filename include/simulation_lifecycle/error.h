#ifndef __SIMULATION_LIFECYCLE_ERROR_H__
#define __SIMULATION_LIFECYCLE_ERROR_H__

/* STANDARD ERRORS 0-99 */
/* Common errors 0-49 */
#define SUCCESS 0
#define GENERIC_ERROR 1
/* File-related errors 50-74 */
#define FILE_EXISTS_ERROR 50
#define FILE_DOES_NOT_EXIST 51
#define UNABLE_OPEN_FILE 52
#define UNABLE_CLOSE_FILE 53
#define UNABLE_WRITE_FILE 54
#define JSON_UNABLE_TO_PARSE 60
#define GEOJSON_UNABLE_TO_PARSE 61
#define JSON_VALUE_INVALID 75
/** WORKFLOW ERRORS 100-199 **/
#define WORKFLOW_DOES_NOT_EXIST 100
#define NULL_DATA_SOURCES 101
#define DATA_SOURCE_ID_MISSING 102
#define DATA_SOURCE_PATH_MISSING 103
#define INVALID_DATA_SOURCE_ARGS 104
#define NULL_SPATIAL_ANALYSIS 105
#define NULL_VISUALIZATION 106
#define NULL_SIMULATION 107
#define WORKFLOW_CONTAINS_EMPTY_JSON_OBJ 108
#define DUPLICATE_DATA_SOURCE_ID 109
#define DUPLICATE_DATA_SOURCE_PATH 110
/** SPATIAL ANALYSIS ERRORS 200-299 **/
#define DATA_SOURCE_PATH_NULL 200
#define DATA_SOURCE_ID_NULL 201
#define WORKFLOW_NO_OPERATIONS 202
#define OPERATION_INVALID_REGISTER 203
#define OPERATION_INVALID_PARAMETERS 204
#define OPERATION_NO_PARAMETERS 205
#define OPERATION_UNREGISTERED 206
#define OPERATION_NAME_NULL 207



/** SIMULATION ERRORS 300-399 **/
#define SIM_CONFIG_EMPTY 300
/* model selection issues 305-309 */
#define SIM_MODEL_SELECTION_INVALID 305
/* model configuration issues 310-320*/
#define SIM_MODEL_COMMON_CONFIG_INVALID 310
#define SIM_MODEL_CELLS_CONFIG_INVALID 311
#define SIM_MODEL_CELL_MAPPING_INVALID 312
#define SIM_MODEL_VICINITIES_CONFIG_INVALID 313
#define SIM_MODEL_VICINITY_MAPPING_INVALID 314
#define SIM_CONFIG_OUTPUT_PATH_INVALID 340
#define SIM_RESULT_OUTPUT_PATH_INVALID 341
#define SIM_RESULT_OUTPUT_PATH_ALREADY_EXISTS 342
/* run simulation issues 350-359 */
#define SIM_RUN_ERROR 350
#define SIM_RUN_NO_RESULTS 351
#define SIM_RUN_RESULTS_MOVE_FAILED 352
/** VISUALIZATION ERRORS 400-499 */
// TODO
/* temporary uncategorized issues 500-599 */


/** CONVERSION ERRORS 500-599 */
#define CONVERT_INPUT_PATH_INCORRECT 500
#define CONVERT_INPUT_PATH_FOLDER_ERROR 501
#define CONVERT_FILE_FORMAT_INCORRECT 502
#define CONVERSION_FAILED 503
#define CONVERT_PATH_FILES_INCORRECT 504

#endif //__SIMULATION_LIFECYCLE_ERROR_H__
