### 解题思路
此处撰写解题思路

### 代码

```rust
use std::collections::HashMap;
impl Solution {
    pub fn count_characters(words: Vec<String>, chars: String) -> i32 {
        let mut chars_cnt:HashMap<char,i32> = HashMap::new();
        for ch in chars.chars() {
            if chars_cnt.contains_key(&ch){
                chars_cnt.insert(ch,chars_cnt[&ch]+1);
            }else{
                chars_cnt.insert(ch,0);
            }
        }
        let mut ans:i32 = 0;
        for word in words {
            let mut word_cnt:HashMap<char,i32> = HashMap::new();
            for ch in word.chars(){
                if word_cnt.contains_key(&ch){
                    word_cnt.insert(ch,word_cnt[&ch]+1);
                }else{
                    word_cnt.insert(ch,0);
                }
            }
            
            let mut is_ans = true;
            for ch in word.chars() {
                if !chars_cnt.contains_key(&ch) || chars_cnt[&ch] < word_cnt[&ch] {
                    is_ans = false;
                    break;
                } 
            }
            //println!("{}--{}",word,is_ans);
            if is_ans{
                ans += word.len() as i32;
            }
        }
        return ans;
    }
}


```