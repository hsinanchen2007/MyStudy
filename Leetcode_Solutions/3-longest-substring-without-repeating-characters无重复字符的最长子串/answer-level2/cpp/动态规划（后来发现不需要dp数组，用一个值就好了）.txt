### 解题思路
动态规划，用dp[i]表示以第i个字母开头的最长的序列长度，本来dp开了个数组，后来发现不需要，然后就用int dp 了

### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int dp;
        dp = 0;
        bool cnt[256];
        memset(cnt, 0, sizeof(cnt));
        int res = 0;
        int len = s.size();
        for(int i = 0; i < len; i++)
        {
            if(cnt[s[i]] == 0)
            {
                dp++;
                cnt[s[i]] = 1;
            }
            else break;
        }
        res = dp;
        for(int j = 1; j < len; j++)
        {
            dp = dp - 1;
            cnt[s[j - 1]] = 0;
            for(int k = max(j,j + dp); k < len; k++)
            {
                if(cnt[s[k]] == 0)
                {
                    dp++;
                    cnt[s[k]] = 1;
                }
                else break;
            }
            if(res < dp)res = dp;
        }
        return res;
    }
};
```