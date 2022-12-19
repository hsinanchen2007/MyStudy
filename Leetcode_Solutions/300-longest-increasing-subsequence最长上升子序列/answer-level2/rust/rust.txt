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
        let mut dp:Vec<usize> = vec![0;n];
        for i in 0..n {
            dp[i] = 1;
            for j in 0..i {
                if nums[j] < nums[i] {
                    dp[i] = dp[i].max(dp[j]+1);
                }
            }
        }

        return *dp.iter().max().unwrap() as i32;
    }
}

```