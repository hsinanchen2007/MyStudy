提供一种 Rust的解法。

0ms，2M 对于可能溢出的情况采用 i64绕过i32上限。


```
use std::i32::MAX;
use std::i32::MIN;

const MAX_D10: i32 = MAX / 10;
const I32_MAX_I64: i64 = MAX as i64;
const I32_MIN_I64: i64 = MIN as i64;

impl Solution {
    pub fn reverse(x: i32) -> i32 {
        let n = x < 0;
        let mut x_mut = x.abs();
        let mut res = 0;
        while x_mut > 0 {
            if res >= MAX_D10 {
                let res_long = res as i64 * 10 + x_mut as i64 % 10;
                if n && res_long < I32_MIN_I64 {
                    return 0;
                }
                if res_long > I32_MAX_I64 {
                    return 0;
                }
                res = res_long as i32;
                break;
            }
            res = res * 10 + x_mut % 10;
            x_mut = x_mut / 10;
        }
        if n { 0 - res } else { res }
    }
}
```
