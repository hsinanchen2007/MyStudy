### 解题思路
直接用个哈希表计数每个字符串，相同的就放在一起，Rust的函数式还是方便

### 代码

```rust
impl Solution {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
        strs.into_iter().fold(std::collections::BTreeMap::new(), |mut map, s| {
            let mut key = std::collections::BTreeMap::new();
            s.as_bytes().iter().for_each(|&c| *key.entry(c).or_insert(0) += 1);
            map.entry(key).or_insert(vec![]).push(s);
            map
        }).into_iter().map(|(_, v)| v).collect()
    }
}
```