### 解题思路


### 代码

```cpp
class Solution {
public:
    int numDecodings(string s) {
        int dp[10010] = {0};
        int n = s.length();
        dp[0] = s[0] == '0' ? 0 : 1;
        if(n == 1)
        return dp[0];
        if(s[0] > '2' && s[1] == '0')
            return 0;
        for(int i = 1 ; i < n ; ++i)
        {
            int temp = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if(s[i] == '0')
            {
                if(temp == 10 || temp == 20)
                    dp[i] = i == 1 ? 1 : dp[i - 2];
                else
                    return 0;
            }
            else
            {
                if(temp < 10 || temp > 26)
                    dp[i] = dp[i - 1];
                else
                    dp[i] = i == 1 ? 2 : dp[i - 1] + dp[i - 2];
            }
        }
        return dp[n - 1];
    }
};
```