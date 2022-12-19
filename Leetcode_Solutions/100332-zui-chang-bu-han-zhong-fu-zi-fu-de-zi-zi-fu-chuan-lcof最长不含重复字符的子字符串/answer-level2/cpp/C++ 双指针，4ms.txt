### 解题思路
提高效率的核心是不用map或unrodered_map，我也不知道为啥他们的效率会差这么多，用了unordered_map后36ms

### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mark[128];
        for (int i = 0; i < 128; ++i) mark[i] = -1;

        int left = 0, right = 0;
        int max = 0;
        for (; right < s.size(); ++right)
        {
            int stop = mark[s[right]];
            if (stop != -1)
            {
                int len = right - left;
                if (len > max) max = len;
                for (; left <= stop; ++left) mark[s[left]] = -1;
            }
            mark[s[right]] = right;
        }
        int len = right - left;
        if (len > max) max = len;
        return max;
    }
};
```