### 解题思路
Fn = Max(F(n-1), F(n-2)+An)

### 代码

```rust
impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32 {
        let mut dp = vec![0; nums.len() + 1_usize];
        for i in 1..=nums.len() {
            if i < 3 {
                dp[i] = nums[i - 1].max(dp[i-1]);
            } else {
                dp[i] = dp[i - 1].max(dp[i - 2] + nums[i-1]);
            }
        }
        dp[nums.len()]
    }
}
```