```
impl Solution {
    fn back_trace(s: &str, idx: usize, rec: &mut Vec<String>, ans: &mut Vec<String>) {
        if s.len() == 0 {
            return;
        }
        if idx == 1 {
            if s[0..].len() > 3 {
                return;
            }
            if s[0..].len() > 1 && &s[0..1] == "0" {
                return;
            }
            if s.parse::<i32>().unwrap() <= "255".parse::<i32>().unwrap() {
                rec.push(s.to_string());
                ans.push(rec.join("."));
                rec.pop();
            }
        } else {
            for i in 0..s.len() {
                if s[0..=i].len() > 1 && &s[0..1] == "0" {
                    continue;
                }
                if s[0..=i].len() > 3 {
                    return;
                } 
                if  s[0..=i].parse::<i32>().unwrap() > 255 {
                    return;
                }
                rec.push(s[0..=i].to_string());
                Self::back_trace(&s[(i + 1)..], idx - 1, rec, ans);
                rec.pop();
            }
        }
    }
    pub fn restore_ip_addresses(s: String) -> Vec<String> {
        let mut ans = vec![];
        let mut rec = vec![];
        Self::back_trace(&s, 4, &mut rec, &mut ans);
        ans
    }
}
```
