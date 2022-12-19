这个题目的解法前面两个题解都讲的很清楚了,本质上就是滑动窗口,至于如何存储子串中的字符其实不是太重要. 下面给出一个c++的解法实现

```
class Solution {
public:
  int lengthOfLongestSubstringKDistinct(string s, int k) {
    const char* str_p = s.c_str();
    map<char, int> char_map;
    const char *sub_start_p = str_p, *sub_end_p = str_p;

    // edge case
    if (k == 0 || s.size() == 0) {
      return 0;
    }

    int max_length = 0;
    char_map[*sub_start_p] = 1;
    while (*sub_end_p != '\0') {
      int sub_length = sub_end_p - sub_start_p + 1;
      if (max_length < sub_length) {
        max_length = sub_length;
      }

      // end shift right 1 char
      sub_end_p ++;
      if (char_map.find(*sub_end_p) != char_map.end()) {
        char_map[*sub_end_p] += 1;
      } else {
        if (char_map.size() == (size_t)k) {
          // we have to shift left cursor to make sure keys smaller than k
          while (char_map.size() == (size_t)k) {
            char_map[*sub_start_p] -= 1;
            if (char_map[*sub_start_p] == 0) {
              char_map.erase(*sub_start_p);
            }
            sub_start_p ++;
          }
          char_map[*sub_end_p] = 1;
        } else {
          char_map[*sub_end_p] = 1;
        }
      }
    }

    return max_length;
  }
};
```
