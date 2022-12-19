### 解题思路
不是一个很难的题，分解出最小子问题：dp[2]=dp[1]*a+dp[0]*b
                a=s[1]==0?0:1    b=(s[0]==0||s[0]*10+s[1]>26)?0:1
状态方程：f(n)=f(n-1)*a+f(n-1)*b
初始状态：f(0)=1, f(1)=(s[0]==0)?0:1

### 代码

```cpp
class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()) return 0;
        int n=s.size();
        int dp[n+1];
        dp[0]=1;
        if(s[0]=='0') dp[1]=0;
        else dp[1]=1;
        for(int i=2; i<=n; i++){
            bool flag=true;
            if(s[i-2]=='0' || (s[i-2]-'0')*10+(s[i-1]-'0')>26) flag=false;
            dp[i]=(s[i-1]=='0'?0:dp[i-1])+(flag?dp[i-2]:0);
        }
        return dp[n];
    }
};
```