# 因为想不周全，测试用例奇奇怪怪的。

```
impl Solution {
    pub fn my_atoi(str: String) -> i32 {
        let mut positive_negtive = true;
        let v: Vec<char> = str.chars().collect();
        let mut res_str = String::new();
        let mut have_symbol = false;
        let mut have_number = false;
        for ch in v {
            match ch {
                '+' => {
                    if have_symbol {
                        break;
                    } else {
                        if have_number {
                            break
                        } else {
                            positive_negtive = true;
                            res_str.push('+');
                            have_symbol = true;
                        }
                    }
                },
                '-' => {
                    if have_symbol {
                        break;
                    } else {
                        if have_number {
                            break
                        } else {
                            positive_negtive = false;
                            res_str.push('-');
                            have_symbol = true;
                        }
                    }
                },
                ch if char::is_numeric(ch) => {
                    res_str.push(ch);
                    have_number = true;
                },
                ' ' => { if res_str.len() == 0 { continue; } else { break; } }
                _ => { break; },
            }
        }
        if res_str.len() == 0 {
            return 0;
        } else {
            if res_str.as_str().eq("+") {
                return 0;
            } else if res_str.as_str().eq("-") {
                return 0;
            };
        }
        use std::str::FromStr;
        match i32::from_str(res_str.as_str()) {
            Ok(res) => { res }
            Err(_) => { if positive_negtive { i32::max_value() } else { i32::min_value() } }
        }
    }
}
```
