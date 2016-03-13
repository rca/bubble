#include <stdlib.h>
#include <check.h>

#include "../bubble.h"


START_TEST(test_swap_array)
{
  int x[] = {5, 4, 3, 2, 1};
  int swaps = 0;

  /* call swap_array, should get back:
     {4, 3, 2, 1, 5}
  */
  swaps = swap_array(x, 5);

  ck_assert_int_eq(x[0], 4);
  ck_assert_int_eq(x[1], 3);
  ck_assert_int_eq(x[2], 2);
  ck_assert_int_eq(x[3], 1);
  ck_assert_int_eq(x[4], 5);

  ck_assert_int_eq(swaps, 4);
}
END_TEST


START_TEST(test_swap)
{
    int x[] = {4, 5};

    swap(x, 0);

    ck_assert_int_eq(x[0], 5);
    ck_assert_int_eq(x[1], 4);
}
END_TEST


START_TEST(test_bubble_sort)
{
    int x[] = {2549, 8877, 1112, 26892};

    /* call bubble_sort, should get back:
       {1112, 2549, 8877, 26892}
    */
    bubble_sort(x, 4);  /* in-place array sorting */

    ck_assert_int_eq(x[0], 1112);
    ck_assert_int_eq(x[1], 2549);
    ck_assert_int_eq(x[2], 8877);
    ck_assert_int_eq(x[3], 26892);
}
END_TEST


Suite * bubble_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Bubble");

    /* test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_bubble_sort);
    tcase_add_test(tc_core, test_swap);
    tcase_add_test(tc_core, test_swap_array);

    suite_add_tcase(s, tc_core);

    return s;
}


int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = bubble_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
