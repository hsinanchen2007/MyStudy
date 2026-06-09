```
impl Solution {
    pub fn longest_valid_parentheses(s: String) -> i32 {
        let sb = s.as_bytes();
        let mut max = 0;
        let mut v = vec![1;s.len()];
        for i in 0..sb.len() {
            if sb[i] == b')' {
                v[i] = 2;
            }
        }
        for i in 0..v.len() {
            if v[i] == 2 {
                for j in (0..i).rev() {
                    if v[j] == 1 {
                        v[i] = 0;
                        v[j] = 0;
                        break;
                    }
                }
            }
        }
        let mut continue_zero_counter = 0;
        for i in 0..v.len() {
            if v[i] == 0 {
                continue_zero_counter += 1;
            } else {
                max = std::cmp::max(max, continue_zero_counter);
                continue_zero_counter = 0;
            }
        }
        std::cmp::max(max, continue_zero_counter)
    } 
}
```
