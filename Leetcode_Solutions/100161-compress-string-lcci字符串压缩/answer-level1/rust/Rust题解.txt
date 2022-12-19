### 解题思路
此处撰写解题思路

### 代码

```rust
impl Solution {
    pub fn compress_string(s: String) -> String {
        if s.len() == 0 {
            return s;
        }
        let mut chars = s.chars();
        let first_char = chars.next().unwrap();
        let mut current: char = first_char;
        let mut current_num: i32 = 1;
        let mut result: String = first_char.to_string();
        for char_ in chars {
            // println!("current: {}, current_num: {}, char: {:?}", current, current_num, char_);
            if char_ != current {
                result = result + &current_num.to_string();
                result = result + &char_.to_string();
                current_num = 1;
            } else {
                current_num = current_num + 1;
            }
            current = char_;
            // println!("{:?}", result);
        }
        result = result + &current_num.to_string();
        // println!("{:?}", result);
        if result.len() >= s.len() {
        return s;
        }
        return result;
    }
}
```