### 解题思路
//状态转移方程： dp[i][j] = Min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
//注意边界条件 没有左上角和右上角的情况

### 代码

```rust
impl Solution {
    pub fn minimum_total(triangle: Vec<Vec<i32>>) -> i32 {
        let n = triangle.len();
        if n == 0 {
            return 0;
        }
        let m = triangle[n - 1].len();
        if m == 0 {
            return 0;
        }
        let mut dp = vec![vec![0; m]; n];
        //初始化
        dp[0][0] = triangle[0][0];
        for i in 1..n {
            for j in 0..triangle[i].len() {
                if j == 0 {
                    //没有左上角
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];
                } else if j == triangle[i].len() - 1 {
                    //没有右上角
                    dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                } else {
                    dp[i][j] = dp[i - 1][j - 1].min(dp[i - 1][j]) + triangle[i][j];
                }
            }
        }
        //获取最后一行最小值
        let mut result = i32::max_value();
        for i in 0..m {
            result = result.min(dp[n - 1][i]);
        }
        result
    }
}
```