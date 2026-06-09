```rust
impl Solution {
    pub fn balanced_string_split(s: String) -> i32 {
        s
        .chars()
        .scan(0,|acc,e| {
            *acc =  match e{
            'R'=>(*acc+1),
            'L'=>(*acc-1),
            _=>(*acc)
            };
            Some(*acc)
        })
        .filter(|e| *e==0)
        .count() as i32
    }
}
```