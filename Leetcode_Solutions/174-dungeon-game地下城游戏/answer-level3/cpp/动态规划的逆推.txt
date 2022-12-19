### 解题思路
用动态规划解决问题，dp[m][n]表示走到m，n的表格位置时，此时骑士的生命值。（若骑士最终到达终点，则生命值必须大于等于1）
一、初始化
  1）最后m,n表格里的值，在减去当前dungeon里的值之后，必须还要大于1，才能活着。dp[m-1][n-1] = max(1, -dungeon(m-1,n-1) +1);
  2) 最后m-1行的,第i列由第i+1列逆推出来，所以dp[m-1][i] = dp[m-1][i+1] - dungeon[m-1][i],但是保证骑士活着，需要生命值至少为1。
  3) 最后n-1列的，第i行由第i+1行逆推出来，所以dp[i][n-1] = dp[i+1][n-1] -dungeon[i][n-1],保证骑士活着，需要生命值至少为1。
二、递推
   第i行、第j列的dp值取决于dp[i][j+1],dp[i+1][j]减去dungen[i][j]之后的最小值。（只需要保证至少有一条路径骑士活着，所以取最小值）

### 代码

```cpp
class Solution {
public:
    //动态规划，倒推
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        dp[m-1][n-1] = max(1, -1*dungeon[m-1][n-1] + 1);
        for(int i = m-2; i>= 0; i--){
            dp[i][n-1] = max(1 , dp[i+1][n-1]-dungeon[i][n-1]);
        }
        for(int i = n-2; i>=0; i--){
            dp[m-1][i] = max(1, dp[m-1][i+1]-dungeon[m-1][i]);
        }
        for(int i = m-2; i>= 0; i--){
            for(int j = n-2; j>=0; j--){
                dp[i][j] = max(1, min(dp[i][j+1], dp[i+1][j])- dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
};
```