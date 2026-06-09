### 动态规划
由于每一步只能够向右走和向下走，因此每一个格子里面的最大值应该为上方和左边种最大的那一个再加上当前格子的值，根据这一思路可以得到递推公式：
$$
f(n)
\begin{cases}
grid[i][j], &i=0,j=0\\
max(dp[i-1][j],dp[i][j-1])+grid[i][j], &i-1>=0, j-1>=0\\
dp[i-1]+grid[i][j], &j-1<0\\
dp[j-1]+grid[i][j], &i-1<0\\
\end{cases}
$$

### 时间/空间复杂度

时间复杂度：O（n2）
空间复杂度：O（n2）


### 代码

```cpp
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int rows=grid.size(),cols=grid[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols,0));
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                if(i==0&&j==0) dp[i][j]=grid[i][j];
                else if(i-1>=0&&j-1>=0){
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1])+grid[i][j];
                }else if(i-1<0){
                    dp[i][j]=dp[i][j-1]+grid[i][j];
                }else if(j-1<0){
                    dp[i][j]=dp[i-1][j]+grid[i][j];
                }
            }
        }
        return dp[rows-1][cols-1];
    }
};
```