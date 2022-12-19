time: 0ms , memory: 2mb;
```rust 
impl Solution {
    pub fn multiply(num1: String, num2: String) -> String {
        if num1 == "0" || num2 == "0" {
            return "0".to_owned();
        }
        let l1 = num1.len();
        let l2 = num2.len();
        let mut r: Vec<u16> = vec![0; l1 + l2 - 1];
    
        for (p1, c1) in num1.char_indices() {
            for (p2, c2) in num2.char_indices() {
                r[p1 + p2] = r[p1 + p2] + (c1 as u16 - '0' as u16) * (c2 as u16 - '0' as u16);
            }
        }
        
        let mut step = 0u64;
        let mut b;
        let mut s = String::with_capacity(l1 + l2);
        for bit in r.iter().rev() {
            b = *bit as u64 + step;
            step = b / 10;
            b = b % 10;
            s.push_str(&format!("{}", b));
        }
        if step > 0 {
            s.push_str(&format!("{}", step));
        }
        s.chars().rev().collect()
    }
}
```
