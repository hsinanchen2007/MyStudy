感觉写动态规划题的时候有2点比较重要：
1. 递推方程，
2. 初始状态，尤其是自己的下标是从0开始还是从1开始，这里编程时很容易出错；

dp[i][j]表示前i天完成前j项任务所需的最小难度,i、j都是从0开始数。
对于dp[i][j]，前i天完成前j项任务，
它有多种选择，可以是前i-1天完成k-1项任务(因为每天至少完成一项所以，k-1>=i-1)，然后第i天完成第k,k+1,...,i项任务，
所需的难度即dp[i-1][k-1] + max{jobDifficulty[k],jobDifficulty[k+1],...,jobDifficulty[i]}
为了完成的难度最低，我们从中选最小的即可，即dp[i][j]=min{dp[i-1][k-1] + max{jobDifficulty[k],jobDifficulty[k+1],...,jobDifficulty[i]}},i <= k <=jobDiffculty.size()。

```
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(jobDifficulty.size()<d){
            return -1;
        }
        vector<vector<int>> dp(d,vector<int>(jobDifficulty.size(),INT_MAX/3));
        int preDif = 0;
        //初始化
        for(int i=0;i<jobDifficulty.size();++i){
            preDif=max(preDif,jobDifficulty[i]);
            dp[0][i]=preDif;
        }
        for(int i=1;i<d;i++){前第i天
            for(int j=i;j<jobDifficulty.size();++j){//前j项任务
                preDif = jobDifficulty[j];
                for(int k=j;k>=i;k--){//前k项任务
                    preDif = max(preDif,jobDifficulty[k]);
                    dp[i][j]=min(dp[i][j],dp[i-1][k-1]+preDif);
                }
            }
        }
        return dp[d-1][jobDifficulty.size()-1];
    }
};
```
时间复杂度：O(dn^2)
