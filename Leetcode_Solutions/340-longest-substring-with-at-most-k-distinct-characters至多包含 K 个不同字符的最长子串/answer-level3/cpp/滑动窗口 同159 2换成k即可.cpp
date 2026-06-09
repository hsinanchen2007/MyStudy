```
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int cnt[256] = {};
        int ans = 0, st = 0, total_cnt = 0;
        for (int en = 0; en < s.size(); ++en) {
            if (!cnt[s[en]]) {
                ++total_cnt;
            }
            ++cnt[s[en]];
            while (total_cnt > k) {
                --cnt[s[st]];
                if (!cnt[s[st]]) {
                    --total_cnt;
                }
                ++st;
            }
            ans = max(ans, en - st + 1);
        }
        return ans;        
    }
};
```