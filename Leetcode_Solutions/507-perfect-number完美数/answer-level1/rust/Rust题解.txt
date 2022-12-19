```Rust
impl Solution {
    pub fn check_perfect_number(num: i32) -> bool {
        if num <= 1 {
            return false;
        }

        let mut sum = 1;
        let mut i = 2;

        while i * i < num {
            if num % i == 0 {
                sum += i + num / i;
            }
            i += 1;
        }

        if i * i == num {
            sum += i;
        }

        sum == num
    }
}
```
[其他题目的Rust题解](https://github.com/fruit-in/LeetCode/blob/master/README_CN.md)