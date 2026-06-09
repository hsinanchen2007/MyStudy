### 解题思路
此处撰写解题思路

### 代码

```rust
impl Solution {
    pub fn count_characters(words: Vec<String>, chars: String) -> i32 {
        let mut result: i32 = 0;
        for word in words {
            let mut a = true;
            let mut new_char = chars.clone();
            for char_ in word.chars() {
                let find_result = new_char.find(char_);
                if find_result.is_none() {
                a = false;
                break
                }
                new_char.remove(find_result.unwrap());
            }
            // println!("{}, {}", word, a);
            if a {
                result += word.len() as i32;
            }
        }
        return result;  
    }
}
```