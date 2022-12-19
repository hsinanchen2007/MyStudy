```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        unordered_map<char, int> window;
        int res = 0; // 记录最长长度
        while (right < s.size()) {
            char c1 = s[right];
            window[c1]++;
            // 如果 window 中出现重复字符
            // 开始移动 left 缩小窗口
            while (window[c1] > 1) {
                char c2 = s[left];
                window[c2]--;
                left++;
            }
            res = max(res, right - left + 1);
            right++;
        }

        return res;
    }

};
```
