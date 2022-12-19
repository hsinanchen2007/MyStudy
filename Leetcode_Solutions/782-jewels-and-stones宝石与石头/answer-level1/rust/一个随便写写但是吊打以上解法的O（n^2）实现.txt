```rust
impl Solution {
    pub fn num_jewels_in_stones(j: String, s: String) -> i32 {
        s.chars()
            .filter(|&chr| { 
                j.chars()
                    .any(|ch| ch == chr)
            })
            .count() as i32
    }
}
```