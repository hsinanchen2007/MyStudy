### 解题思路
双指针 left、right 记录考察子字符串的位置，用哈希表存储字符的位置，如果发现有重复指针，需要判断哈希表中重复字符的位置是否在 left 之后，如果是，则更新 maxlen 和 left。

### 发现
如果哈希表可以用 vector 去模拟就尽量用 vector，不要用 unordered_map 和 map。两种方式我都尝试过，结果是用 vector 去模拟哈希表会快很多。

### 代码
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> table(128, -1);
        int left = -1, right, maxlen = 0;
        for (right = 0; right < s.size(); right++) {
            if (table[s[right]] == -1 || left > table[s[right]]) {
                table[s[right]] = right;
            } else {
                maxlen = max(maxlen, right-left-1);
                left = table[s[right]];
                table[s[right]] = right;
            }
        }
        return max(maxlen, right-left-1);
    }
};
```
![Xnip2020-03-17_17-38-27.jpg](https://pic.leetcode-cn.com/d1a32b1400fce4803f1965c77cf2a6a5d5614b31ba2d2fa240906625933d0b5d-Xnip2020-03-17_17-38-27.jpg)
