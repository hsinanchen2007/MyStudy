0 毫秒的 rust 解答

BTreeMap 比 HashMap 省内存

```rust
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        use std::collections::BTreeMap;
        let mut map: BTreeMap<i32, usize> = BTreeMap::new();
        let mut result: Vec<i32> = vec![-1; 2];
        for (i, &v) in nums.iter().enumerate() {
            let key = &(target - v);
            if map.contains_key(key) {
                let j = *map.get(key).unwrap();
                result[0] = j as i32;
                result[1] = i as i32;
                break;
            }
            map.insert(v, i);
        }
        result
    }

```
