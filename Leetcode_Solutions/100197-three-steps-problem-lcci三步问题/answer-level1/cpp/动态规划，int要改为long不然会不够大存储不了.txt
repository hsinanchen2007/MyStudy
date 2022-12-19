### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int waysToStep(int n) {
        if(n==0)return 0;
        if(n==1)return 1;
        if(n==2)return 2;
        if(n==3)return 4;
        long dp[n+1];
        dp[1]=1;
        dp[2]=2;
        dp[3]=4;
        for(int i=4;i<=n;i++)
            dp[i]=(dp[i-3]+dp[i-2]+dp[i-1])%1000000007;
        return dp[n];
    }
};
```