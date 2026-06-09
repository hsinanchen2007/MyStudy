### 解题思路
此处撰写解题思路

### 代码

```rust
use std::collections::HashMap;
impl Solution {
    pub fn gcd(a:i32, b:i32) -> i32 {
        match a%b {
            0 => b,
            _ => Solution::gcd(b,a%b)
        }
    }
    pub fn has_groups_size_x(deck: Vec<i32>) -> bool {
        let mut cnt:HashMap<i32,i32> = HashMap::new();
        for &d in &deck{
            let num = cnt.entry(d).or_insert(0);
            *num+=1;
        }
        let mut g = -1;
        for &val in cnt.values(){
            g = match g {
                -1 => val,
                _  => Self::gcd(g,val)
            };
        }
        g >= 2
    }
}
```