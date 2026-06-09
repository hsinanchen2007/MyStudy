### 1. 使用HashMap
```
use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut res = vec![];
        let mut cache = HashMap::new();

        for (index, item) in nums.iter().enumerate() {
            let sub = target - *item;

            match cache.get(item) {
                Some(pre_index) => {
                    res.push(*pre_index);
                    res.push(index as i32);
                    return res
                },
                None => {
                    cache.insert(sub, index as i32);
                },
            }
        }
        res
    }
}
```


### 2. 暴力遍历

```
impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut res = vec![];
        for (i, value_i) in nums.iter().enumerate() {
            for (j, value_j) in nums[i+1..].iter().enumerate() {
                if value_i + value_j == target {
                    res.push(i as i32);
                    res.push((i+j+1) as i32);
                    return res
                }
            }
        }
        res
    }
}

```
