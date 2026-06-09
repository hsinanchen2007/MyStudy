### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int integerBreak(int n) {
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[1]=1;
        for(int i=2;i<=n;i++)
            for(int j=1;j<i;j++)
                dp[i]=max(dp[i],max(j*dp[i-j],j*(i-j)));
        return dp[n];
    }
};
```