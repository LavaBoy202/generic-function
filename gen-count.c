#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "gen-count.h"
#include "cs136-trace.h"
#include <string.h>
int generic_map(void *arr, int len, size_t size,
                bool (*map_function)(void *)) {
  int count = 0;
  char *arr_base = arr;
  for (int i = 0; i < len; ++i) {
    //trace_int(arr_base + i * size);
    if (map_function(arr_base + i * size) == true){
      count++;
    }
  }
  return count;
}
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
int gen_count(void *arr, int len, size_t size, bool (*match)(void *)) {
  assert(arr);
  assert(size > 0);
  assert(len > 0);
  assert(match);
  return generic_map(arr, len, size, match);
}


static const char *string_match = "hotdog";

bool hotdog(void *pint) {
  assert(pint);
  const char **p = pint;
  if(strcmp(*p, string_match) == 0) {
    return true;
  }else{
    return false;
  }
}

// count_hotdog(strings, len) returns the number of strings in strings
//  that are exactly equal to the string "hotdog"
// note: "hotdog" and "HotDog" are not equal
// requires: strings is a valid array (not NULL)
//           len > 0
//           the length of strings is len [not asserted]
//           the elements of strings are valid strings [not asserted]
// time: O(n) where n is the number of strings
//       (remember, "hotdog" is a constant)
int count_hotdog(char *strings[] , int len) {
  assert(len > 0);
  assert(strings);
  return gen_count(strings, len, sizeof(char *), hotdog); // dummy value
}


static const int radius = 5;

bool rad (void *pint) {
  const struct posn *p = pint;
  int x = p->x;
  int y = p->y;
  if (((x * x) + (y * y)) <= (radius * radius)) {
    return true;
  }
  return false;
}

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
int count_circle(struct posn points[], int len) {
  assert(points);
  assert(len > 0);
  return gen_count(points, len, sizeof(struct posn), rad);
}
