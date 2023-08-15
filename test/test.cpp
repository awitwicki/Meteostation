#include <unity.h>

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_circular_buffer_empty_after_init() {
    int a = 5;
    int b = 5;

    //bool result = a == b;

    TEST_ASSERT_TRUE(true);
}


int main( int argc, char **argv) {
    UNITY_BEGIN();

    RUN_TEST(test_circular_buffer_empty_after_init);

    UNITY_END();
}
