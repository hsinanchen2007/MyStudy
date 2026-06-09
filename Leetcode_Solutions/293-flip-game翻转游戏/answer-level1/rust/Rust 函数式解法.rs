```rust
impl Solution {
    pub fn generate_possible_next_moves(s: String) -> Vec<String> {
        s
        .chars()
        .zip(s.chars().skip(1))
        .enumerate()
        .filter(|e| (e.1).0 =='+' && (e.1).1=='+')
        .map(|e| {
            let mut v = s.clone();
            v.replace_range((e.0 .. e.0+2),"--");
            v
        })
        .collect::<Vec<String>>()
    
    }
}
```