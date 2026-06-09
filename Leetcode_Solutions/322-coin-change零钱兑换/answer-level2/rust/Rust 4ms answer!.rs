### 解题思路
此处撰写解题思路

### 代码

```rust
impl Solution {
    pub fn coin_change(coins: Vec<i32>, amount: i32) -> i32 {
        let mut dp = vec![i32::max_value();(amount + 1) as usize];
        dp[0] = 0;
        for i in 1..(amount+1) as usize {
            for &j in &coins {
                if i as i32 - j >= 0 && dp[i - j as usize] != i32::max_value() {
                    dp[i] = dp[i].min(dp[i - j as usize] + 1);
                }
            }
        }
        return if dp[amount as usize] == i32::max_value() {-1} else {dp[amount as usize]}
    }
}
```