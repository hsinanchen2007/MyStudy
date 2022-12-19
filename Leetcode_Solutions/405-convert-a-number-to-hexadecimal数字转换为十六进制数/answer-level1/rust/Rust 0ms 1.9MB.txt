### 解题思路


### 代码

```rust
impl Solution {
    pub fn to_hex(num: i32) -> String {
        if num == 0 {
            return "0".to_string();
        }
        let s = "0123456789abcdef";
        let m = 0x0000000f;
        let mut n: i64 = num as i64 & 0xffffffff;
        let mut r = String::new();
        while n > 0 {
            r.push(s.chars().nth((n & m) as usize).unwrap());
            n >>= 4;
        }
        r.chars().rev().collect::<String>()
    }
}
```