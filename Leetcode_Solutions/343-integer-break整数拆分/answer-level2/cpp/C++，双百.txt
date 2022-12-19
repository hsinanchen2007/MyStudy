### 解题思路
此处撰写解题思路
令dp[i]表示分解i对应的最大乘积，那么i可以分解为k和i-k(2<=k<=i/2)，那么可以想到dp[i]=max(dp[i],dp[k]*dp[i-k])，但是如果dp[k]<k，也即将k分解之后乘积变小，那么就不分解k，所以dp[i]=max(dp[i],max(dp[j],j)*max(dp[i-j],i-j));
### 代码

```cpp
class Solution {
public:
    int dp[59];
    int integerBreak(int n) {
      dp[1]=1;
       for(int i=2;i<=58;i++)dp[i]=i-1;
       for(int i=3;i<=n;i++){
           for(int j=2;j<i;j++){
               dp[i]=max(dp[i],max(dp[j],j)*max(dp[i-j],i-j));
           }
       }
       return dp[n];
    }
};
```