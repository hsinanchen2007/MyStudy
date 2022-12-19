leetcode这种题比较常见，所有的子串问题都可以这么解决，比如每个字符至少k次的最长子串。
```cpp
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (s.size() <= k) return s.size();
        int begin = 0, end = 0, counter = 0, ans = 0;
        int hash[128] = {0};
        while (end < s.size()) {
            if (hash[s[end++]]++ == 0) counter ++;
            while (counter > k) {
                if (hash[s[begin++]] -- == 1) counter --;
            }
            ans = max(ans, end - begin);
        }
        return ans;
    }
};
```