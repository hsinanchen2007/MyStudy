```Rust
use std::collections::HashMap;

impl Solution {
    pub fn num_jewels_in_stones(j: String, s: String) -> i32 {
        let mut jewels = HashMap::new();
        for ch_j in j.chars() {
            jewels.insert(ch_j, 0);
        }
        for ch_s in s.chars() {
            if let Some(i) = jewels.get(&ch_s) {
                jewels.insert(ch_s, i + 1);
            }
        }
        jewels.values().sum()
    }
}
```
[其他题目的Rust题解](https://github.com/fruit-in/LeetCode/blob/master/README_CN.md)
