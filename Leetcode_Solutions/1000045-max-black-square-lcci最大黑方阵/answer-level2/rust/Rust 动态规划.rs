用一个二维数组记录某个位置最长连续0个数（行和列），然后沿着对角线检查是否满足边是否是包围的，条件是：
- `matrix[i - diff][j - diff] == 0`
- `dp[i - diff][j - diff].0 + diff == dp[i - diff][j].0`
- `dp[i - diff][j - diff].1 + diff == dp[i][j - diff].1`
这里`diff`最大取`min(dp[i][j].0, dp[i][j].1)`。
检查并记录可能的最大边长，最后返回结果即可。

```rust
use std::cmp::{max, min};
impl Solution {

    pub fn find_square(matrix: Vec<Vec<i32>>) -> Vec<i32> {
        let mut dp = vec![vec![(0, 0); matrix[0].len()]; matrix.len()];
        let mut max_len = 0;
        let mut pos = (0, 0);
        for i in 0..matrix.len() {
            for j in 0..matrix[i].len() {
                if matrix[i][j] == 0 {
                    let mut row = 1;
                    let mut col = 1;
                    if i > 0 && matrix[i - 1][j] == 0 {
                        col += dp[i - 1][j].1;
                    }
                    if j > 0 && matrix[i][j - 1] == 0 {
                        row += dp[i][j - 1].0;
                    }
                    dp[i][j] = (row, col);

                    // cal max
                    let mut len = 1;
                    let mut k = min(row, col) as usize;
                    let mut diff = 1;
                    while diff < k {
                        if matrix[i - diff][j - diff] == 0 {
                            if dp[i - diff][j - diff].0 + diff == dp[i - diff][j].0
                                && dp[i - diff][j - diff].1 + diff == dp[i][j - diff].1 {
                                len = 1 + diff;
                            }
                        }
                        diff += 1;
                    }
                    if len > max_len {
                        max_len = len;
                        pos = (i, j);
                    }
                }
            }
        }
        if max_len > 0 {
            return vec![(pos.0 + 1 - max_len) as i32 , (pos.1 + 1 - max_len) as i32,
                        max_len as i32];
        }
        return vec![];
    }
}
```