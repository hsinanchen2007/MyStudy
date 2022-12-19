### rust 替换

```rust []
impl Solution {
    pub fn replace_space(s: String) -> String {
        let mut ans = String::from("");
        for c in s.chars() {
            match c {
                ' ' => ans += "%20",
                _ => ans += &c.to_string()
            }
        }
        ans
    }
}
```
```rust []
impl Solution {
    pub fn replace_space(s: String) -> String {
        s.replace(" ", "%20")
    }
}
```