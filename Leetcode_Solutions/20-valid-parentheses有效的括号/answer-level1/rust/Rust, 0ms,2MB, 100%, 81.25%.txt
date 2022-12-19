```
impl Solution {
    pub fn is_valid(s: String) -> bool {
        let mut v = vec!['0']; //确保pop出有效值, 防止 ")"
        for x in s.chars() {
            match x {
                '('| '[' | '{' => { v.push(x); },
                ')' => {if v.pop().unwrap() != '(' { return false; } },
                ']' => {if v.pop().unwrap() != '[' { return false; } },
                '}' => {if v.pop().unwrap() != '{' { return false; } },
                _ => (),
            }
        }
        v.len() == 1
    }
}
```
