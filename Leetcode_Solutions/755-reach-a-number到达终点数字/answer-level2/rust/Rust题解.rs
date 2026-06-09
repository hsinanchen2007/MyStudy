```Rust
impl Solution {
    pub fn reach_number(target: i32) -> i32 {
        let mut target = target;
        let mut position = 0;
        let mut step = 0;
        if target < 0 {
            target = -target;
        }
        while position < target {
            step += 1;
            position += step;
        }
        if (position - target) % 2 == 0 {
            step
        } else if step % 2 == 0 {
            step + 1
        } else {
            step + 2
        }
    }
}
```
[其他题目的Rust题解](https://github.com/fruit-in/LeetCode/blob/master/README_CN.md)
