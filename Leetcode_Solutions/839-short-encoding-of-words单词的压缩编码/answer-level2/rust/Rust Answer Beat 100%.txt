### 解题思路
反转后排序后就很明了
例如
time,me,bell
反转排序后
"em", "emit", "lleb"
那么后缀相同的就排到了相邻的位置。因为只要判断words[i-1]是不是words[i]的开头，如果是则说明words[i-1]是words[i]的后缀。

### 代码

```rust
use std::collections::HashSet;
impl Solution {
    pub fn minimum_length_encoding(words: Vec<String>) -> i32 {
        let mut words_re :Vec<String>= words.clone().into_iter().map(|w| w.chars().rev().collect::<String>()).collect();
        words_re.sort();
        let mut ans = 0;
        (1..words_re.len()).for_each(|i| {
            let word:&String = &words_re[i];
            let pre :&String = &words_re[i-1];
            if !word.starts_with(pre) {
                ans += &words_re[i-1].len() + 1;
            }
        });
        ans += words_re.last().unwrap().len() + 1;
        ans as i32
    }
}
```