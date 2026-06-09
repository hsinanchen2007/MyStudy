```Rust
impl Solution {
    pub fn dominant_index(nums: Vec<i32>) -> i32 {
        let m = *nums.iter().max().unwrap();
        if nums.iter().all(|&x| 2 * x <= m || x == m) {
            nums.iter().position(|&x| x == m).unwrap() as i32
        } else {
            -1
        }
    }
}
```
[其他题目的Rust题解](https://github.com/fruit-in/LeetCode/blob/master/README_CN.md)
