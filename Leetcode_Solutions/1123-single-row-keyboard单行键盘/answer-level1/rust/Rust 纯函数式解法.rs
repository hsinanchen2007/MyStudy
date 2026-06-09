```Rust
use std::collections::{HashMap};
impl Solution {
    pub fn calculate_time(keyboard: String, word: String) -> i32 {
        let khash: HashMap<_, _>  = keyboard
        .chars()
        .zip((0..keyboard.len() as i32) )
        .collect();
        
        word
        .chars()
        .zip( word .chars() .skip(1))
        .map( |(a,b)| i32::abs(khash.get(&a).unwrap()-khash.get(&b).unwrap() ))
        .fold(*khash.get(&word .chars() .nth(0) .unwrap()).unwrap(), |a,b| a + b)
    }
}
```