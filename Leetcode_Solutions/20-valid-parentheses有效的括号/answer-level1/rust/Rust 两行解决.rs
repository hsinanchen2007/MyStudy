```rust
pub fn is_valid(s: String) -> bool {
    let mut v = Vec::new();
    s.len() & 1 == 0 && s.bytes().all(|b| Some(match b { b'(' | b'{' | b'[' => { v.push(b); return true }, b')' => b'(', b'}' => b'{', b']' => b'[', _ => panic!() }) == v.pop()) && v.is_empty()
}
```
利用 ASCII 码的更短
```rust
s.len() & 1 == 0 && s.bytes().all(|b| match b { b'(' | b'{' | b'[' => { v.push(b); true }, _ => b - v.pop().unwrap_or(0) <= 2 }) && v.is_empty()
```