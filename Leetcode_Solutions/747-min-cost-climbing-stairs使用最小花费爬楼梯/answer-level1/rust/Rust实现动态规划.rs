### 解题思路
说白了就是动态规划，有一说一，Rust真的啰嗦

### 代码

```rust
use std::cmp::Ordering;

impl Solution {
    pub fn min_cost_climbing_stairs(cost: Vec<i32>) -> i32 {
        let mut f1 = 0;
        let mut f2 = 0;
        for i in 1..(cost.len()+1) as usize {
            let s = cost.len() - i;
            let mut f0 = cost[s] + match f1.cmp(&f2) {
                Ordering::Greater => f2,
                _ => f1,
            };
            f2 = f1;
            f1 = f0;
        }

        match f1.cmp(&f2) {
            Ordering::Greater => return f2,
            _ => return f1,
        }
    }
}
```