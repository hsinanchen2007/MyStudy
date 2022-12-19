```Rust
impl Solution {
    pub fn find_length_of_lcis(nums: Vec<i32>) -> i32 {
        let mut i = 0;
        let mut max_len = 0;

        for j in 1..=nums.len() {
            if j == nums.len() || nums[j] <= nums[j - 1] {
                max_len = max_len.max(j - i);
                i = j;
            }
        }

        max_len as i32
    }
}
```
[其他题目的Rust题解](https://github.com/fruit-in/LeetCode/blob/master/README_CN.md)
