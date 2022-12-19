### 解题思路
借鉴的别人的！

### 代码

```cpp
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n == 1)
        return s[0] == '0'?0:1;
        else{
            vector<int> dp(n,0);

            if(s[0] == '0')
            return 0;
            else
            {
                dp[0]++;
                if(s[0]<'2'||(s[0] == '2'&&s[1]<'7')) dp[1]++;
                if(s[1]!='0') dp[1]++;
            }

            for(int i = 2;i<n;i++)
            {
                if(s[i]!='0') dp[i] += dp[i-1];
                if(s[i-1]>'0'&&(s[i-1]<'2'||(s[i-1] == '2'&&s[i]<'7'))) dp[i]+=dp[i-2];
            }
return dp[n-1];
        }

        
        
    }
};
```