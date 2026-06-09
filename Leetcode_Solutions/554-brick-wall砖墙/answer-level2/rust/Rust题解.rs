```Rust
use std::collections::HashMap;

impl Solution {
    pub fn least_bricks(wall: Vec<Vec<i32>>) -> i32 {
        let mut map = HashMap::new();

        for row in &wall {
            let mut sum = 0;
            for i in 0..(row.len() - 1) {
                sum += row[i];
                *map.entry(sum).or_insert(0) += 1;
            }
        }

        wall.len() as i32 - map.values().max().unwrap_or(&0)
    }
}
```
[其他题目的Rust题解](https://github.com/fruit-in/LeetCode/blob/master/README_CN.md)
