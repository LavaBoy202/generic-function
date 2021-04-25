# generic-function
Part A)

You must write the function gen_count which, similar to bsearch and qsort,
is passed a void pointer to an array.  gen_count is also passed a function
that checks items of this array, and returns the total number of items that
pass the test.

For example, given a function is_even(n) which returns true if and only if
n is an even number, then gen_count(arr_of_ints, len, sizeof(int), is_even)
returns the total number of even ints in arr_of_ints.

See the test client for more details.

Part B)

You must now write the following two functions that use gen_count
Both functions *must* use gen_count in a meaningful way
(meaning that basically all the functions should do is call gen_count and
return what gen_count returns).

See gen-count.h for details.

int count_hotdog(char *strings[], int len);

int count_circle(struct posn items[], int len);

These functions are not tested in the provided test client.
You should create your own test client that tests these functions,
but only once you have Part A working.

