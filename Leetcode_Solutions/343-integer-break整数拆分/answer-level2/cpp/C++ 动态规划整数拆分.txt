动态规划求解，dp[i]代表i分割之后得到的乘积最大的元素，有些类似于最长上升子序列，每次需要和之前所有的状态进行比较，状态转移方程式为dp[i]=max(dp[i],(i-j)*max(dp[j],j)),(i>j)，因为dp[j]未曾包括不分割当前元素乘积最大的情况，因此需要加以考虑.
```
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,0);
        dp[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<i;j++){
                dp[i]=max(dp[i],max((i-j)*dp[j],(i-j)*j));
            }
        }
        return dp.back();
    }
};
```