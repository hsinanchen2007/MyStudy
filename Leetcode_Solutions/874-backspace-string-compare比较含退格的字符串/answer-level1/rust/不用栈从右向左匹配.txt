```rust
impl Solution {
    pub fn backspace_compare(s: String, t: String) -> bool {
        let mut s_it = s.chars().rev().peekable();
        let mut t_it = t.chars().rev().peekable();
        loop {
            let mut s_p = 0;
            // 从右向左消耗掉#和#删除的字符
            // peek时看一眼下一个字符，但迭代器不更新，next会更新迭代器
            while s_p >= 0 {
                if let Some('#') = s_it.peek() {
                    s_p += 1;
                    s_it.next();
                } else {
                    if s_p > 0{
                        s_it.next();
                    }
                    s_p -= 1;
                }
            }
            let mut t_p = 0;
            while t_p >= 0 {
                if let Some('#') = t_it.peek() {
                    t_p += 1;
                    t_it.next();
                } else {
                    if t_p > 0{
                        t_it.next();
                    }
                    t_p -= 1;
                }
            }
            match (s_it.next(), t_it.next()) {
                (Some(c), Some(d)) if c==d => {continue;},
                (None, None) => {return true;},
                _ => {return false;}
            }
        }
    }
}
```
