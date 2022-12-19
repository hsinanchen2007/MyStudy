# 问题描述

给定一组单词， 找到在每个单词里重复出现的字母， 返回这些字母。并且相同的字母也要按照出现的次数来返回。

# 限定条件

单词只包含小写字母。

# 思路

对每个单词建立一个字母统计表，记录每个字母的出现次数。 然后对比各个单词， 得到共同出现的字母的最小出现次数。

```rust
const ascii_a: u8 = 'a' as u8;

impl Solution {
    pub fn common_chars(a: Vec<String>) -> Vec<String> {
        let mut freqs = vec![];
        for word in a {
            let mut freq = [0;26];
            for letter in word.chars() {
                let index = (letter as u8 - ascii_a) as usize;
                freq[index] += 1;
            }
            freqs.push(freq.clone());
        }
        let mut result = vec![];
        for i in 0..26 {
            let min = freqs.iter().map(|&f| f[i]).min().unwrap();
            for _ in 0..min {
                let i = i as u8;
                let letter = ((i + ascii_a) as char).to_string();
                result.push(letter.clone());
            }
        }
        result
    }
}
```
