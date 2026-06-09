### 解题思路
其实也就是动态规划的事情，但是需要考虑太多的条件。
比如非法字符串非法。比如"0", "306", "100"。需要添加一层判断。

状态转移方程为：f(n) = f(n-1), 或者f(n) = f(n-1) + f(n-2),这两种情况又是一堆判断。
### 代码

```cpp
class Solution {
public:
//  需要考虑非法的编码!比如30
    int numDecodings(string s) {
        int len = s.size();
        if(len == 1 && s[0] != '0') return 1;

        //考虑非法的编码
        for(int j = 0; j < len; j++)
        {
            if(j == 0 && s[j] == '0')
            {
                return 0;
            }
            if(s[j] == '0' && (s[j-1] - '0' > 2 || s[j-1] == '0'))
            {
                return 0;
            }
        }
        int dp[len];
        dp[0] = 1;
        int secondS = (s[len-2] - '0')*10+(s[len-1] - '0');
        if((secondS > 10 && secondS < 20) || (secondS > 20 && secondS < 27))
        {
            dp[1] = 2;
        }
        else{
            dp[1] = 1;
        }
        for(int i = 2; i < len; i++)
        {
            int sn = s[len-i-1] - '0';
            if((sn>=3 && sn <=9) || sn == 0)
            {
                dp[i] = dp[i-1];
                continue;
            }
            int sn_1 = s[len-i] - '0';
            int sn_2 = s[len-i+1] - '0';
            if(sn == 1)
            {
                if(sn_1 == 0 || sn_2 == 0)
                {
                    dp[i] = dp[i-1];
                }
                else
                {
                    dp[i] = dp[i-1] + dp[i-2];
                }
            }
            if(sn == 2)
            {
                if(sn_1 == 0 || sn_1 > 6 || sn_2 == 0)
                {
                    dp[i] = dp[i-1];
                }
                else
                {
                    dp[i] = dp[i-1] + dp[i-2];
                }
            }

        }

        return dp[len-1];
    }
};
```