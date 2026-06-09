### 运行结果

![image.png](https://pic.leetcode-cn.com/db64adb5a0f18d1609a3f43f396125d5997ff9a69d71a3210cbe91f6e8b9b785-image.png)

### 解题思路

统计奇数个数和偶数个数

### 代码

```rust
use std::cmp::min;

impl Solution {
    pub fn min_cost_to_move_chips(chips: Vec<i32>) -> i32 {
        let len = chips.len();

        let mut even_count = 0i32;
        for item in chips {
            if 0 == item & 0x01 {
                even_count += 1;
            }
        }

        min(even_count, len as i32 - even_count)
    }
}
```
