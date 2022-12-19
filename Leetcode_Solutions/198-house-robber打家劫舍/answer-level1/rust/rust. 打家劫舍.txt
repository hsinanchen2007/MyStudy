### 解题思路
此处撰写解题思路

### 代码

```rust
impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        if n==0 {
            return 0;
        }
        let mut dp:Vec<i32>=vec![0;n+1];
        dp[1]=nums[0];
        for i in 2..n+1{
            dp[i]=dp[i-1].max(dp[i-2]+nums[i-1]);
        }
        dp[n]
    }
}
```