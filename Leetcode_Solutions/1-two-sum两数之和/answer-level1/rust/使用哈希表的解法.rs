```rust
use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map: HashMap<i32, i32> = HashMap::new();
        for (i, item) in nums.iter().enumerate() {
            let complement = target - item;
            if map.contains_key(&complement) {
                return vec![*map.get(&complement).unwrap(), i as i32];
            } else {
                map.insert(*item, i as i32);
            }
        }
        vec![0, 0]
    }
}

```
