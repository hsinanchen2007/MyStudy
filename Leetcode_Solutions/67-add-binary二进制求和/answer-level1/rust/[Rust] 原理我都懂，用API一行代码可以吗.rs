```
impl Solution {
    pub fn add_binary(a: String, b: String) -> String {
       format!("{:b}", i128::from_str_radix(a.as_str(),2).unwrap() + i128::from_str_radix(b.as_str(),2).unwrap())
    }
}
```
