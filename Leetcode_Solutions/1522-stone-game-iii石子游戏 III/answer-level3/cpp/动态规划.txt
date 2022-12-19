1. 比较传统的题目，我们设立dp动态规划。`dp[i]`代表从`i`处开始行游戏，在最优策略下直到游戏结束时，所能取到的最多的石子数目。`sum[i]`代表从i到n的石子的总的数目；
2. 递推公式为：
$$
dp[i] = max
\left\{
\begin{aligned}
\sum_{k = 0}^{0}stones[i+k] + sum[i+1] - dp[i+1] \\
\sum_{k = 0}^{1}stones[i+k] + sum[i+2] - dp[i+2] \\
\sum_{k = 0}^{2}stones[i+k] + sum[i+3] - dp[i+3] \\
\end{aligned}
\right.
$$
3. 我们倒序从最后的元素开始计算，设dp[n] = 0;我们在O(N)的时间复杂度内既可以求出结果。
```c++
class Solution {
public:
  
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> sum(n+1,0);
        vector<int> dp(n+1,INT_MIN);
        for(int i = n-1; i >= 0; --i) sum[i] = sum[i+1] + stoneValue[i];
      
        dp[n] = 0;
        for(int i= n-1; i >= 0; --i){
            int curr = 0;
            for(int j = i; j < n && j <= i + 2; j++){
                curr += stoneValue[j];
                dp[i] = max(dp[i],curr+sum[j+1]-dp[j+1]);
            }
        }
        
        if(dp[0] == sum[0] - dp[0]) return "Tie";
        if(dp[0] > sum[0] - dp[0]) return "Alice";
        return "Bob";
    }
};
```