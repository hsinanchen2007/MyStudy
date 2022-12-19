```Rust
impl Solution {
    pub fn matrix_reshape(nums: Vec<Vec<i32>>, r: i32, c: i32) -> Vec<Vec<i32>> {
        if nums.len() * nums[0].len() != (r * c) as usize {
            return nums;
        }

        nums.concat()
            .chunks(c as usize)
            .map(|row| row.to_vec())
            .collect()
    }
}
```
[其他题目的Rust题解](https://github.com/fruit-in/LeetCode/blob/master/README_CN.md)
