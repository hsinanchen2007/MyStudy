```rust
impl Solution {
    pub fn gray_code(n: i32) -> Vec<i32> {
        let mut r = vec![0];
        for i in 0..n{
            let mut temp = vec![];
            let more = 1<<i;
            for it in r.iter().rev(){
                temp.push(*it+more);
            }
            r.extend(temp);
        }
        r
    }
}
```