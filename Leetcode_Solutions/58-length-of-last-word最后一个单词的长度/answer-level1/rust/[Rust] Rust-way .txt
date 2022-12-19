```
impl Solution {
    pub fn length_of_last_word(s: String) -> i32 {
        let mut s = s;
        let mut res = 0_i32;
        while let Some(c) = s.pop() {
            if c == ' ' && res == 0 {
                continue;
            } else if c == ' ' && res != 0 {
                break;
            } else {
                res += 1;
            }
        }
        res
    }
}
```
