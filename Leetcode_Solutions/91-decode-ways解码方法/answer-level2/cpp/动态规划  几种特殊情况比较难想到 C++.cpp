### 解题思路
几种关于'0'的特殊情况提交了几遍，比较难想到

### 代码

```cpp
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n==0)  return 0;
        int dp[n];
        if(s[0]=='0')  return 0;
        else  dp[0]=1;
        if(n==1)  return dp[0];
        if((s[0]-'0')*10+s[1]-'0'>26) 
        {
            if(s[1]=='0') return 0;
            else dp[1]=1;
        } 
        else if(s[1]=='0') dp[1]=1;     
        else dp[1]=2;
        for(int i=2;i<n;i++)
        {
            if(s[i]=='0')
            {
                if(s[i-1]=='1'||s[i-1]=='2')
                    dp[i] = dp[i-2];
                else
                    return 0;
            }
            else if((s[i-1]-'0')*10+s[i]-'0'>26||s[i-1]=='0')
                dp[i] = dp[i-1];
            else
                dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n-1];
    }
};

```