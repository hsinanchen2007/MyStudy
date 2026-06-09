### 解题思路
此处撰写解题思路

### 代码

```rust
use std::collections::HashMap;
impl Solution {
    pub fn longest_palindrome(s: String) -> i32 {
        let mut result: i32 = 0;
        let chars_ = s.chars();
        let mut counts: HashMap<char, i32> = HashMap::new();
        for char_ in chars_ {
            counts.insert(char_, counts.get(&char_).unwrap_or(&0) + 1);
        }
        for count in counts {
            let v = count.1;
            result += v / 2 * 2;
            if v % 2 == 1 && result % 2 == 0 {
                result += 1;
            }
        }
        return result;
    }
}
```