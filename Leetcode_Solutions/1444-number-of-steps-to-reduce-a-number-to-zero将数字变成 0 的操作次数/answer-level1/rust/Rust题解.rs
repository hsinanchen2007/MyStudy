```Rust
impl Solution {
    pub fn number_of_steps (num: i32) -> i32 {
        let mut num = num;
        let mut ret = 0;

        while num != 0 {
            match num % 2 {
                0 => num /= 2,
                _ => num -= 1,
            }
            ret += 1;
        }

        ret
    }
}
```
[其他题目的Rust题解](https://github.com/fruit-in/LeetCode/blob/master/README_CN.md)
