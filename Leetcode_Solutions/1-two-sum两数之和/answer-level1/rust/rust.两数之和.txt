### 解题思路
此处撰写解题思路

### 代码

```rust
use std::collections::HashMap;
impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut hashmap:HashMap<i32,i32>=HashMap::new();
        for i in 0..nums.len(){
            if(hashmap.contains_key(&(target-nums[i]))){
                return vec![i as i32,hashmap[&(target-nums[i])]];
            }else{
                hashmap.insert(nums[i],i as i32);
            }
        }
        return vec![]
    }
}
```