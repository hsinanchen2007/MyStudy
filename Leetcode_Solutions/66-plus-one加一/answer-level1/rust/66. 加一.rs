
### 代码

```rust
impl Solution {
    pub fn plus_one(digits: Vec<i32>) -> Vec<i32> {
       let mut carry = 0;
       let mut digits = digits;
       let last_index = digits.len() - 1;
       digits[last_index] += 1;
       for index in (0..digits.len()).rev() {
           digits[index] += carry;
           carry = digits[index] / 10;
           digits[index] %= 10;
       }
       if carry == 1 {
           digits.insert(0, 1);
       }
       digits
    }
}
```