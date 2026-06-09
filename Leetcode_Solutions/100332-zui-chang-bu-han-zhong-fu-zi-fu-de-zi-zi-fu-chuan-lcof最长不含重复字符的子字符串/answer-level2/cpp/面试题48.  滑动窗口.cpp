```cpp
// 滑动窗
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int freq[256] = {0};  // 比map快
        // unordered_map<char, int> freq;
        int l = 0, r = -1;  // [l,r]窗口内是不含重复字符的字符串，初始化范围[0,-1]，是个空窗
        int res = 0;
        // while (r+1 < s.size()) {
        while (l < s.size()) {

            if (r + 1 < s.size() && freq[s[r+1]] == 0)  //find 和 erase比直接索引慢
                freq[s[++r]] = 1;
            else
                freq[s[l++]] = 0;

            res = max(res, r-l+1);
        }
        return res;
        
    }
};
```