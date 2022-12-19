### 解题思路
此处撰写解题思路

### 代码

```rust
impl Solution {
    pub fn reverse_words(s: String) -> String {
        s.split(" ").filter(|val| val != &"").collect::<Vec<&str>>().into_iter().rev().collect::<Vec<&str>>().join(" ")
    }
}
```