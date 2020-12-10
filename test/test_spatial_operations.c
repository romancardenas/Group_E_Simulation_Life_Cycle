#include <unity.h>
#include <cJSON.h>
#include "simulation_lifecycle/error.h"
#include "simulation_lifecycle/utils/linked_list.h"
#include "simulation_lifecycle/utils/workflow.h"
#include "simulation_lifecycle/spatial_analysis.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_SBA_missing_data(void) {

    cJSON * workflow = NULL;
    node_t * data_sources = NULL;

    read_json_file("../test/data/spatial_operations/3_missing_data_SBA.json", &workflow);
    read_data_in(workflow, &data_sources);

    cJSON * operation = read_spatial_analysis(workflow)->child;
    cJSON * params = cJSON_GetObjectItem(operation, "parameters");

    TEST_ASSERT_EQUAL(SBA_DATA_MISSING, select_by_attributes_execute("odhf_facil", &data_sources, params));
}

void test_SBA_missing_data_source(void) {

    cJSON * workflow = NULL;
    node_t * data_sources = NULL;

    read_json_file("../test/data/spatial_operations/4_missing_data_source_SBA.json", &workflow);
    read_data_in(workflow, &data_sources);

    cJSON * operation = read_spatial_analysis(workflow)->child;
    cJSON * params = cJSON_GetObjectItem(operation, "parameters");

    TEST_ASSERT_EQUAL(SBA_MISSING_DATA_SOURCE, select_by_attributes_execute("odhf_facil", &data_sources, params));
}

void test_SBA_missing_field(void) {

    cJSON * workflow = NULL;
    node_t * data_sources = NULL;

    read_json_file("../test/data/spatial_operations/5_missing_field_SBA.json", &workflow);
    read_data_in(workflow, &data_sources);

    cJSON * operation = read_spatial_analysis(workflow)->child;
    cJSON * params = cJSON_GetObjectItem(operation, "parameters");

    TEST_ASSERT_EQUAL(SBA_MISSING_FIELD, select_by_attributes_execute("odhf_facil", &data_sources, params));
}

void test_SBA_missing_value(void) {

    cJSON * workflow = NULL;
    node_t * data_sources = NULL;

    read_json_file("../test/data/spatial_operations/6_missing_value_SBA.json", &workflow);
    read_data_in(workflow, &data_sources);

    cJSON * operation = read_spatial_analysis(workflow)->child;
    cJSON * params = cJSON_GetObjectItem(operation, "parameters");

    TEST_ASSERT_EQUAL(SBA_MISSING_VALUE, select_by_attributes_execute("odhf_facil", &data_sources, params));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_SBA_missing_data);
    RUN_TEST(test_SBA_missing_data_source);
    RUN_TEST(test_SBA_missing_field);
    RUN_TEST(test_SBA_missing_value);
    return UNITY_END();
}
