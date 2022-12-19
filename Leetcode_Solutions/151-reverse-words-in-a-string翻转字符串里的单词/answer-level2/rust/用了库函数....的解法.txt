```rust
pub fn reverse_words(s: String) -> String {
    s.split(' ')
        .rev()
        .filter(|x| !x.is_empty())
        .collect::<Vec<&str>>()
        .join(" ")
}
```