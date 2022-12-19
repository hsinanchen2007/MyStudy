### 解题思路
注意循环的条件和方向是这道题的关键

### 代码

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() <= 1)
            return s;
        int n = s.length();
        int dp[n][n] = {0};
        for(int i = 0 ; i < n ; ++i)
            dp[i][i] = 1;
        int maxx = 1, st = 0;
        for(int i = 1 ; i < n ; ++i)
        {
            if(s[i - 1] == s[i])
            {
                dp[i - 1][i] = 1;
                maxx = 2;
                st = i - 1;
            }
        }
        for(int i = n - 3 ; i >= 0 ; --i)
        {
            for(int j = n - 1 ; j > i + 1 ; --j)
            {
                if(s[i] == s[j])
                {
                    dp[i][j] = dp[i + 1][j - 1];
                    if(dp[i][j] && j - i + 1 > maxx)
                    {
                        maxx = j - i + 1;
                        st = i;
                    }
                }
            }
        }
        return s.substr(st, maxx);
    }
};
```