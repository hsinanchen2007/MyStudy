滑动窗口
```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        unordered_map<char, int> a;
        int l = 0;
        int r = 0;
        for(; r < s.size(); r++) {
            if(a[s[r]] == 0) {
                a[s[r]]++;
                res = max(res, r - l + 1);
            } else {
                while(l < r) {
                    l++;
                    if(s[l - 1] == s[r]) {
                        break;
                    }
                    a[s[l-1]]--;
                }
            }
        }
        return res;
    }
};
```
