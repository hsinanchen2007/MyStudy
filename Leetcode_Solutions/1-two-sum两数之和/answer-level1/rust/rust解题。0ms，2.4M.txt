### 解题思路
此处撰写解题思路

### 代码

```rust
use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map_: HashMap<i32, i32> = HashMap::new();
        for index in 0..nums.len() {
            map_.insert(*nums.get(index).unwrap(), index as i32);
        }
        for index in 0..nums.len() {
            let temp = target - nums.get(index).unwrap();
            let other_index = map_.get(&temp);
            if other_index.is_some() && index as i32 != *other_index.unwrap() {
                return vec!(index as i32, *other_index.unwrap());
            }
        }
        return vec!();
    }
}
```