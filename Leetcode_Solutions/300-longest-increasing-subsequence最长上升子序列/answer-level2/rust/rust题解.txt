### 解题思路
此处撰写解题思路

### 代码

```rust
impl Solution {
    pub fn length_of_lis(nums: Vec<i32>) -> i32 {
        let n = nums.len();
    if n == 0 {
      return 0;
    }
    let mut dp: Vec<i32> = vec![0; n];
    dp[0] = 1;
    let mut result = 1;
    for i in 1..n {
      let mut max_val = 0;
      for j in 0..i {
        if nums[j] < nums[i] {
          max_val = max_val.max(dp[j]);
        }
      }
      dp[i] = max_val + 1;
      result = result.max(dp[i]);
    }

    return result;
    }
}
```