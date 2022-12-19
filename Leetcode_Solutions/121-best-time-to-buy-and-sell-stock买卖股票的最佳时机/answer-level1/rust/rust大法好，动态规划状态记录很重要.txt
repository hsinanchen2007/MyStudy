### 解题思路
rust大法好，动态规划状态记录很重要

### 代码

```rust
use std::cmp::{min, max};
impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        if prices.len() <= 1 {
            return 0;
        }
        let mut min = prices[0];
        let mut max = 0;
        for v in prices {
            max = max.max(v - min);
            min = min.min(v);
        }
        max
    }
}
```