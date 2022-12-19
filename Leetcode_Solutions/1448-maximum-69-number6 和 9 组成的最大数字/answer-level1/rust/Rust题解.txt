```Rust
impl Solution {
    pub fn maximum69_number (num: i32) -> i32 {
        let mut i = 0;

        for i in (0..5).rev() {
            if num / 10_i32.pow(i) % 10 == 6 {
                return num + 3 * 10_i32.pow(i);
            }
        }

        num
    }
}
```
[其他题目的Rust题解](https://github.com/fruit-in/LeetCode/blob/master/README_CN.md)
