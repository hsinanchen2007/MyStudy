### 解题思路
外层循环控制右指针移动，右指针向后移动一次，找左右指针之间的子串有没有右指针的字符值。如果有则计算子串长度最大值，并移动左指针到找到该位置，进行下一次循环。

### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unsigned int max = 0;
        unsigned int step = 0;
        unsigned int right = 0;
        unsigned int left = 0;
        for (; right < s.length(); right++) {
            for (step=left; step < right; step++) {
                if (s.at(step) == s.at(right)) {
                    max = max > right - left ? max : right - left;
                    left = step + 1;
                    break;
                }
            }
        }
        max = max > right - left ? max : right - left;
        return max;
    }
};
```