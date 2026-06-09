### 解题思路
此处撰写解题思路
运用了hashmap 对字母的出现次数进行统计，当字母的次数不是偶数的时候，为false，里面有个特殊的情况
只有一个字母的时候，也是能够构成回文数的

### 代码

```rust
use std::collections::HashMap;

impl Solution {
    pub fn can_permute_palindrome(s: String) -> bool {
        if s.len() == 1 {
            return true
        }
        let mut res_map = HashMap::with_capacity(s.len());
        for v in s.chars(){
            let count = res_map.entry(v).or_insert(0);
            *count += 1
        }
        println!("map = {:?}", res_map);
        let mut odd = 0;
        for (k, v) in res_map {
            if v % 2 != 0 {
                odd += 1
            }
            if odd > 1 {
                return false
            }
        }
        return true
    }
}
```