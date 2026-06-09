不写分号挑战
```
impl Solution {
    pub fn longest_common_prefix(strs: Vec<String>) -> String {
        strs.get(0).and_then(|s| s.get(0..(0..strs.iter().min_by_key(|s| s.len()).map(|s| s.len()).unwrap_or(0))
            .into_iter()
            .map(|i| {
                strs
                    .iter()
                    .map(|s| s.get(i..(i+1)))
                    .all(|c| c.and_then(|c| strs[0].get(i..(i+1)).map(|d| c == d)).unwrap_or(false)) 
            })
            .take_while(|&ok| ok)
            .count())).unwrap_or("").to_string()
    }
}
```
