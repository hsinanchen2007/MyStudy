```rust
use std::collections::{HashMap};
impl Solution {
    pub fn anagram_mappings(a: Vec<i32>, b: Vec<i32>) -> Vec<i32> {
        let mut t = HashMap::new();

        b
        .iter()
        .enumerate()
        .for_each(|pair| t
                .entry(pair.1 )
                .or_insert_with(Vec::new)
                .push(pair.0 as i32) );

        a
        .iter()
        .map(|e| t
            .get_mut(e)
            .unwrap()
            .pop()
            .unwrap() )
        .collect::<Vec<i32>>()
    
    }
}
```