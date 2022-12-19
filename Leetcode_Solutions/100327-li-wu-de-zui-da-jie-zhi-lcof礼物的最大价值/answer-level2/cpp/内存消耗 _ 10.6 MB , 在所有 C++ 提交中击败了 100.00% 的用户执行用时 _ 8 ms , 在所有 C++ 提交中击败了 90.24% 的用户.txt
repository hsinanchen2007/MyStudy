### 解题思路
此处撰写解题思路
优化内存的DP方法，保存第i行的第j个结果
j左边的是本行结果，右边的是上一行结果，所以使用 max(dp[j], dp[j-1])
### 代码

```cpp
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<int> dp(col,0);
        dp[0] = grid[0][0];
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i == 0){
                    if(j>0)dp[j] = grid[i][j] + dp[j-1];
                }else{
                    if(j==0){
                        dp[j] += grid[i][0];
                    }else{
                        dp[j] = grid[i][j] +  max(dp[j], dp[j-1]);
                    }
                }
            }
        }
        return dp[col - 1];
    }
};
```