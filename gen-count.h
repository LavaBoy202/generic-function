// A module for counting items in generic arrays
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdlib.h>

// SEASHELL_READONLY

// gen_count(arr, len, size, match) returns the number of elements in arr
//   where match returns true.
// requires: arr is a valid array
//           arr is an array of length len [not asserted]
//           len, size > 0
//           the elements of arr are size bytes [not asserted]
//           match is a valid function pointer
//           match's parameter will handle the contents of arr correctly
//             [not asserted]
// time: O(n), assuming match is O(1)
int gen_count(void *arr, int len, size_t size, bool (*match)(void *));


// count_hotdog(strings, len) returns the number of strings in strings
//  that are exactly equal to the string "hotdog"
// note: "hotdog" and "HotDog" are not equal
// requires: strings is a valid array (not NULL)
//           len > 0
//           the length of strings is len [not asserted]
//           the elements of strings are valid strings [not asserted]
// time: O(n) where n is the number of strings
//       (remember, "hotdog" is a constant)
int count_hotdog(char *strings[], int len);

struct posn {
  int x;
  int y;
};

// count_circle(items, len) returns how many posns in items are <= 5
//   units from the origin in a straight line
//   (meaning, they are contained within a circle with radius 5)
// notes: the posn {2, 2} is less than 5 units from the origin
//        the posn {3, 4} is exactly 5 units from the origin
//        the posn {4, 4} is more than 5 units from the origin
// requires: items is a valid array (not NULL)
//           len > 0
//           the length of items is len [not asserted]
// time: O(n)
int count_circle(struct posn items[], int len);
