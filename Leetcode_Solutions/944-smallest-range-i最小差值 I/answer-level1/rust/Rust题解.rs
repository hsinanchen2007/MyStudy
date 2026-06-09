```Rust
impl Solution {
    pub fn smallest_range_i(a: Vec<i32>, k: i32) -> i32 {
        let mut min = a.iter().min().unwrap();
        let mut max = a.iter().max().unwrap();
        if max - min < 2 * k {
            0
        } else {
            max - min - 2 * k
        }
    }
}
```
[其他题目的Rust题解](https://github.com/fruit-in/LeetCode/blob/master/README_CN.md)