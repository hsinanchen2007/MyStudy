### 解题思路
dp[n][m] = Min(dp[n-1][m], dp[n][m-1]) + grid[n][m]

### 代码

```rust
impl Solution {
    pub fn min_path_sum(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        if n==0 {
            return 0;
        }
        let m = grid[0].len();
        if m == 0 {
            return 0;
        }
        let mut dp = vec![vec![0; m]; n];

        for i in 0..n {
            for j in 0..m {
                //初始化第一行、第一列
                if i == 0 || j == 0{
                    dp[i][j] = grid[i][j];
                    if i==0 && j>0 {
                        dp[i][j] += dp[i][j-1];
                    }
                    if j ==0 && i>0 {
                        dp[i][j] += dp[i-1][j];
                    }
                } else {
                    //状态转移方程
                    dp[i][j] = dp[i-1][j].min(dp[i][j-1]) + grid[i][j];
                }
            }
        }
        dp[n-1][m-1]
    }
}
```