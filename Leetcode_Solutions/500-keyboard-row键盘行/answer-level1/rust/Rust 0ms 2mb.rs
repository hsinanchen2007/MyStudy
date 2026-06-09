![image.png](https://pic.leetcode-cn.com/f0d55681c1ee370999e76123c82e1f60655e54b2fd537b593c44cebf664bd9c9-image.png)

```rust
impl Solution {
    pub fn find_words(words: Vec<String>) -> Vec<String> {
        let alphabets = vec![2,3,3,2,1,2,2,2,1,2,2,2,3,3,1,1,1,1,2,1,1,3,1,3,1,3];
        let mut res = Vec::new();
        for word in words {
            let mut last_line = 0;
            for ch in word.chars() {
                let i = (ch.to_ascii_lowercase() as u8 - 'a' as u8) as usize;
                if last_line > 0 && last_line != alphabets[i] {
                    last_line = 4;
                    break;
                }
                last_line = alphabets[i];
            }
            if 4 != last_line { res.push(word); }
        }
        res
    }
}
```
