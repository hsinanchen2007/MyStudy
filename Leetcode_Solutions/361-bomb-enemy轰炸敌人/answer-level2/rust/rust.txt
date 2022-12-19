### 解题思路
//假设敌人、墙的位置都能放炸弹
//分4个方向处理
//汇总后找出最多的空位置

### 代码

```rust
impl Solution {
    pub fn max_killed_enemies(grid: Vec<Vec<char>>) -> i32 {
        let n = grid.len();
        if n == 0 {
            return 0;
        }
        let m = grid[0].len();
        if m == 0 {
            return 0;
        }
        let mut dp = vec![vec![0; m]; n];
        let mut result = vec![vec![0; m]; n];
        //向上
        for i in 0..n {
            for j in 0..m {
                dp[i][j] = 0;
                if grid[i][j] == 'W' {
                    continue;
                }
                if grid[i][j] == 'E' {
                    dp[i][j] = 1;
                }
                if i > 0 {
                    dp[i][j] += dp[i - 1][j];
                }
                result[i][j] += dp[i][j];
            }
        }
        //向下
        for i in (0..n).rev() {
            for j in 0..m {
                dp[i][j] = 0;
                if grid[i][j] == 'W' {
                    continue;
                }
                if grid[i][j] == 'E' {
                    dp[i][j] = 1;
                }
                if i < n - 1 {
                    dp[i][j] += dp[i + 1][j];
                }
                result[i][j] += dp[i][j];
            }
        }

        //向左
        for j in 0..m {
            for i in 0..n {
                dp[i][j] = 0;
                if grid[i][j] == 'W' {
                    continue;
                }
                if grid[i][j] == 'E' {
                    dp[i][j] = 1;
                }
                if j > 0 {
                    dp[i][j] += dp[i][j-1];
                }
                result[i][j] += dp[i][j];
            }
        }

        //向右
        for j in (0..m).rev() {
            for i in 0..n {
                dp[i][j] = 0;
                if grid[i][j] == 'W' {
                    continue;
                }
                if grid[i][j] == 'E' {
                    dp[i][j] = 1;
                }
                if j < m - 1 {
                    dp[i][j] += dp[i][j+1];
                }
                result[i][j] += dp[i][j];
            }
        }

        let mut max = 0;
        for i in 0..n {
            for j in 0..m {
                if grid[i][j] == '0'{
                    max = max.max(result[i][j]);
                }
            }
        }
        max
    }
}
```