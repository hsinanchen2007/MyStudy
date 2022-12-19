空格自己去掉的, 其实应该用trim的
用`i32::overflowing_add()`可能会少一点match
```rust
impl Solution {
    pub fn my_atoi(a: String) -> i32 {
        let mut num:i32 = 0;
        let mut chars = a.chars();
        let mut neg:bool = false;
        let mut counting:bool = false;
        let mut overflow:bool = false;
        loop {
            match chars.next() {
                None => { break; },

                Some('-') => {
                    if counting { break; }
                    counting = true;
                    neg = true;
                },

                Some('+') => {
                    if counting { break; }
                    counting = true;
                    neg = false;
                },

                Some(' ') => { if counting { break; } else { continue; } },

                Some(c) => {
                    match c.to_digit(10) {
                        Some(this_dig) => {
                            if !counting { counting = true; break; }
                            match num.checked_mul(10) {
                                None => { overflow = true; break; },
                                Some(n1) => {
                                    match n1.checked_add(this_dig as i32) {
                                        None => { overflow = true; },
                                        Some(n2) => { num = n2; },
                                    };
                                },
                            };
                        },
                        None => { break; },
                    };
                },
            }
        }
        return if overflow {
            if neg { i32::min_value() } else { i32::max_value() }
        } else {
            if neg { -num } else { num }
        }
    }
}
```
