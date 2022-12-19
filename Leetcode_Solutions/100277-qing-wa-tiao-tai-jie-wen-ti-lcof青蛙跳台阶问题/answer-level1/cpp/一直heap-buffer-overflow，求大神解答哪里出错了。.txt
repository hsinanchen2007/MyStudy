```
class Solution {
public:
    int numWays(int n) {
        //动态规划dp[i],表示第i级台阶有多少种跳法，dp[i]=dp[i-1]+dp[i-2]，青蛙跳上第i级的时候是跳了1级，还是2级
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;//把这两行删了，初始化dp(n+1,1)就过了，搞不明白为什么
        for(int i=2;i<=n;++i)
        {
            dp[i]=(dp[i-1]+dp[i-2])%1000000007;
        }
        return dp[n];
    }
};
```
