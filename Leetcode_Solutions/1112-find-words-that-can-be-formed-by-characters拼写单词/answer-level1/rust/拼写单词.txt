### 解题思路
此处撰写解题思路

### 代码

```rust
impl Solution {
    pub fn count_characters(words: Vec<String>, chars: String) -> i32 {
        use std::collections::HashMap;
        let mut key = HashMap::new();
        for c in chars.as_bytes() {
            let t = key.entry(c).or_insert(0);
            *t += 1;
        }
        let mut len = 0;
        let mut flag: bool;
        for s in words {
            let mut temp = key.clone();
            flag = true;
            for c in s.as_bytes() {
                match temp.get_mut(c) {
                    Some(t) if *t > 0 => *t -= 1,
                    _ => {flag = false; break}
                }
            }
            if flag {
                len += s.len();
            }
        }
        len as i32
    }
}
```