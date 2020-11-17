#ifndef __SIMULATION_LIFECYCLE_ERROR_H__
#define __SIMULATION_LIFECYCLE_ERROR_H__

/* STANDARD ERRORS 0-99 */
/* Common errors 0-49 */
#define SUCCESS 0
#define GENERIC_ERROR 1
/* File-related errors 50-99 */
#define FILE_EXISTS_ERROR 50
#define FILE_DOES_NOT_EXIST 51
#define UNABLE_OPEN_FILE 52
#define UNABLE_CLOSE_FILE 53
#define UNABLE_WRITE_FILE 54

#define JSON_UNABLE_TO_PARSE 60
#define GEOJSON_UNABLE_TO_PARSE 61

/** WORKFLOW ERRORS 100-199 **/
// TODO
/** SPATIAL ANALYSIS ERRORS 200-299 **/
// TODO
/** SIMULATION ERRORS 300-399 **/
/* model selection issues 300-309 */
#define MODEL_EMPTY 300
#define MODEL_NOT_FOUND 301
/* feature set issues 310-319 */
#define FEATURE_SET_EMPTY 310
/* relation set issues 320-329 */
#define RELATION_SET_EMPTY 320
#define INCONSISTENT_DATA 325
/* output path issues 330-339 */
#define OUTPUT_PATH_EMPTY 330
#define OUTPUT_FILE_EXISTS 331
/** VISUALIZATION ERRORS 400-499 */
// TODO
/* temporary uncategorized issues 500-599 */


#endif //__SIMULATION_LIFECYCLE_ERROR_H__
