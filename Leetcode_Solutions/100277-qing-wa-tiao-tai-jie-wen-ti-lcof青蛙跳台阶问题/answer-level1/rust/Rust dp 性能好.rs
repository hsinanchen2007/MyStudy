### 解题思路
dp

### 代码

```rust
impl Solution {
    pub fn num_ways(n: i32) -> i32 {
        if n <= 1 {
            return 1;
        }
        let n = n as usize;
        let mut dp = vec![0u64; n];
        dp[0] = 1;
        dp[1] = 2;
        for i in 2..n {
            dp[i] = dp[i - 1] + dp[i - 2];
            dp[i] %= 1000000007
        }
        dp[n - 1] as i32
    }
}

```