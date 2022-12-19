### 解题思路
思路参考高赞答案。
rust的排序默认已经是字典排序了，所以可以直接处理。

### 代码

```rust
impl Solution {
    pub fn minimum_length_encoding(words: Vec<String>) -> i32 {
        let mut res=0i32;
        let mut words: Vec<String> =words.into_iter().map(|word| word.chars().rev().collect::<String>()).collect();
        words.sort();
        (0..words.len()).for_each(|i| {
            if i+1<words.len() && words[i+1].starts_with(&words[i]){
                res+=0;
            }else{
                res+=words[i].len() as i32+1;
            }
        });
        res
    }
}

```