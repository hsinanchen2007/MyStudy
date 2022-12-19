### 运行结果

![image.png](https://pic.leetcode-cn.com/bad3950fa42d48977d316acd51cd242e0dcc6a66bd9584343882713c4edaa9e2-image.png)

### 解题思路
HashMap

### 代码

```rust
use std::collections::HashMap;

impl Solution {
    pub fn roman_to_int(s: String) -> i32 {
        let map: HashMap<&str, i32> = [("I", 1), ("IV", 4), ("V", 5), ("IX", 9), ("X", 10), ("XL", 40), ("L", 50), ("XC", 90), ("C", 100), ("CD", 400), ("D", 500), ("CM", 900), ("M", 1000)].iter().cloned().collect();
        let mut ans = 0i32;
        let mut one = "0";
        let mut two = "0";
        let mut i = 0usize;
        let len = s.len();
        while i < len {
            one = s.get(i..(i + 1)).unwrap();
            if map.contains_key(&one) {
                if i < len - 1 {
                    two = s.get(i..(i + 2)).unwrap();
                    if map.contains_key(&two) {
                        one = two;
                        i += 1;
                    }
                }
                ans += map.get(&one).unwrap();
                i += 1;
            }
        }
        (ans)
    }
}
```