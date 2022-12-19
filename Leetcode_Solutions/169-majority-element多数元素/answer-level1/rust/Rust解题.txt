### 解题思路
此处撰写解题思路

### 代码

```rust
use std::collections::HashMap;

impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> i32 {
        let mut result_map: HashMap<i32, i32> = HashMap::new();
        for &num in &nums {
            let new_value;
            if result_map.get(&num).is_none() {
                new_value = 1;
            } else {
                new_value = result_map.get(&num).unwrap() + 1;
            }
            result_map.insert(num, new_value);
            if new_value > (nums.len() / 2) as i32 {
                return num;
            }
        }
        return 0;
    }
}
```