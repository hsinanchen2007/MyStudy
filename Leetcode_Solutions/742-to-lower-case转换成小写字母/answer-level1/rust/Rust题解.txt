```Rust
impl Solution {
    pub fn to_lower_case(str: String) -> String {
        let mut lower_case_str = String::new();
        for ch in str.chars() {
            lower_case_str.push(ch.to_ascii_lowercase());
        }
        lower_case_str
    }
}
```
[其他题目的Rust题解](https://github.com/fruit-in/LeetCode/blob/master/README_CN.md)
