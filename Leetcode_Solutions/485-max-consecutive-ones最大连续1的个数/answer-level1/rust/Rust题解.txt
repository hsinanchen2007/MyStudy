```Rust
impl Solution {
    pub fn find_max_consecutive_ones(nums: Vec<i32>) -> i32 {
        let mut i = 0;
        let mut m = 0;
        for n in nums {
            if n == 1 {
                i += 1;
            } else {
                m = m.max(i);
                i = 0;
            }
        }
        m.max(i)
    }
}
```
[其他题目的Rust题解](https://github.com/fruit-in/LeetCode/blob/master/README_CN.md)