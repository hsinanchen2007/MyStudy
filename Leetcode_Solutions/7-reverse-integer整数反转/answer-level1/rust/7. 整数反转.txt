

```rust
impl Solution {
    pub fn reverse(x: i32) -> i32 {
        let mut result: i64 = 0;
        let mut x = x;
        while x != 0 {
            result += (x % 10) as i64;
            x /= 10;
            if x != 0 {
                result *= 10;
            }
        }
        Solution::check_overflow(result)
    }

    pub fn check_overflow(input: i64) -> i32 {
        if input > (std::i32::MAX as i64) || input < (std::i32::MIN as i64) {
            0
        } else {
            input as i32
        }
    }
}
```