### 解题思路
此处撰写解题思路

### 代码

```rust
use std::collections::HashMap;
impl Solution {
    pub fn single_number(nums: Vec<i32>) -> Vec<i32> {
        let mut cnt:HashMap<i32,i32>=HashMap::new();
        let mut ans:Vec<i32>=Vec::new();
        for num in nums{
            let stat=cnt.entry(num).or_insert(0);
            *stat += 1;
        }
        for (&key,&value) in cnt.iter(){
            if value == 1 {
                ans.push(key);
            }
        }
        ans
    }
}
```