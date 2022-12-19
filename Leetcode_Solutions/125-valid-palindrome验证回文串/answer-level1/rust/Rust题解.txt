```
impl Solution {
    pub fn is_palindrome(s: String) -> bool {
        let mut v = Vec::new();
        for c in s.chars() {
            if c >= 'a' && c <= 'z' {
                v.push((c as u8 - 32) as char);
            } else if c >= 'A' && c <= 'Z' || c >= '0' && c <= '9' {
                v.push(c)
            }
        }
        let (mut l, mut r) = (0 as i32, v.len() as i32 - 1);
        while (l <= r) {
            if v[l as usize] == v[r as usize] {
                l += 1;
                r -= 1;
                continue;
            } else {
                return false;
            }
        }
        true
    }
}
```
