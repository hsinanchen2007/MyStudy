### 解题思路
dp[i]代表i拆分成两个以上个数的最大乘积

dp[i]=max(dp[i],max((i-j)*j,j*dp[i-j])),其中 1=<j<i

### 代码

```cpp
class Solution {
public:
    int integerBreak(int n) {
     int dp[n+1]={0};
     dp[1]=1;
     for(int i=1;i<n+1;i++)
       for(int j=1;j<i;j++)
        dp[i]=max(dp[i],max((i-j)*j,j*dp[i-j]));
    return dp[n];
    }
};
```