### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        int maxResult = INT_MIN;
        int maxBegin = 0;
        int maxEnd = 0;
        for (int i = 0; i < s.size(); i++) {
            int lenSingle = Dfs(s, i, i);
            int lenDouble = Dfs(s, i, i + 1);
            int curMax = max(lenSingle, lenDouble);
            if (curMax > (maxEnd - maxBegin + 1)) {
                maxBegin = i - (curMax - 1) / 2;
                maxEnd = i + curMax / 2;
            }
        }
        return s.substr(maxBegin, maxEnd - maxBegin + 1);
    }

    int Dfs(string s, int begin, int end) {
        if (begin < 0 || end >= s.size()) {
            return 0;
        }
        while (begin >= 0 && end < s.size() && s[begin] == s[end]) {
            begin--;
            end++;
        }
        return end - begin - 1;
    }
};
```