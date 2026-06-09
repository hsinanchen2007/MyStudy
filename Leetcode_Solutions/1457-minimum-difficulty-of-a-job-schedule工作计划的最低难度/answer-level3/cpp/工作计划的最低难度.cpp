### 解题思路
题目意思为将jobDiffculty数组划分为d份，使得d份里最大的值加起来和最小。故设立了二维数组dp(d*lenth),dp[i][j]记录第i天完成第j个工作所需要的最低难度。题目要求每天至少要完成一项工作，所以第i天可以完成的工作下标范围为[i,lenth-d+i].所以更新dp第i行的数据时，遍历dp数组：dp[i-1][i-1]-dp[i-1][lenth-d+i-1],更新dp[i][i]--dp[i][lenth-d+i]的数值，具体公式为:dp[i][n] = min(dp[i-1][t] + max(jobDiffculty[j]), dp[i][n])(i=<n<=lenth-d+i, i-1=<t<n,t<j<=n)，最后返回dp[d-1][lenth-1]的值即可

### 代码

```cpp
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int lenth = jobDifficulty.size();
        vector<vector<int>> dp(d,vector<int>(lenth,0));
        vector<int> sk(lenth,0);
        int ans = 0;
        if(lenth < d) return -1;
        if(lenth == d)
        {
           for(auto a:jobDifficulty) ans+=a; 
           return ans;
        }
        //else
        dp[0][0] = jobDifficulty[0];
        for(int i=1;i<=lenth-d;i++)
        {
            dp[0][i] = max(dp[0][i-1], jobDifficulty[i]);
        }
        
        for(int i=1;i<d;i++)
        {
            dp[i][i] = dp[i-1][i-1] + jobDifficulty[i];
            sk[i] = jobDifficulty[i];
            for(int j=i+1;j<=lenth-d+i;j++)
            {
                sk[j] = max(sk[j-1],jobDifficulty[j]);
                dp[i][j] = dp[i-1][i-1] + sk[j];
            }
            for(int j = i;j<=lenth-d+i-1;j++)
            {
                sk[j+1] = jobDifficulty[j+1];
                dp[i][j+1] = min(dp[i-1][j] + sk[j+1],dp[i][j+1]);
                for(int t = j+2;t<=lenth-d+i;t++)
                {
                    sk[t] = max(sk[t-1], jobDifficulty[t]);
                    dp[i][t] = min(dp[i-1][j]+ sk[t], dp[i][t]);
                }
            }
        }
        
        // for(int i=0;i<d;i++)
        // {
        //     for(int j=0;j<lenth;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //         cout<<endl;
        // }
            return dp[d-1][lenth-1];
    }
};
```