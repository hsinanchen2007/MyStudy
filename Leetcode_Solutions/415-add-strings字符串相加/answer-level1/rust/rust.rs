![image.png](https://pic.leetcode-cn.com/c15ac9e1842e1746f28e1f8e4ae2d6b6d2f1f1607bc4848162083b1dbcbaa126-image.png)

```rust
impl Solution {
    pub fn add_strings(mut num1: String, mut num2: String) -> String {
        let mut res = String::new();
        let mut carry = 0u32;
        loop {
            if num1.is_empty() && num2.is_empty() && carry == 0 { break; }            
            if let Some(n1) = num1.pop() { carry += n1.to_digit(10).unwrap(); }
            if let Some(n2) = num2.pop() { carry += n2.to_digit(10).unwrap(); }
            res.push_str(&(carry % 10).to_string());
            carry /= 10;
        }
        res.chars().rev().collect::<String>()
    }
}
```

