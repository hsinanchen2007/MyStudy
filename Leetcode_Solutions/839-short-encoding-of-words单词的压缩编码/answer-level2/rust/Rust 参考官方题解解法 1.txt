![image.png](https://pic.leetcode-cn.com/7ec841a36a171cf16245df4bd30142907dda35880599f88b3a3e245c627c40f3-image.png)
```rs
use std::collections::HashSet;

impl Solution {
    pub fn minimum_length_encoding(words: Vec<String>) -> i32 {
        let mut longs: HashSet<String> = words.clone().into_iter().collect();
        words.iter().for_each(|w| {
            for i in 1..w.len() {
                unsafe {
                    let sub = w.get_unchecked(i..w.len());
                    longs.remove(sub);
                }
            }
        });
        longs.iter().fold(0, |acc, x| { acc + x.len() as i32 + 1 })
    }
}
```