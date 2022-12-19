```
impl Solution {
    pub fn num_jewels_in_stones(j: String, s: String) -> i32 {
        j
        .chars()
        .map(|e|{
            s.as_str()
            .matches(e)
            .collect::<Vec<&str>>()
            .len() as i32
        })
        .fold(0,|a,b|a+b)
    }
}
```