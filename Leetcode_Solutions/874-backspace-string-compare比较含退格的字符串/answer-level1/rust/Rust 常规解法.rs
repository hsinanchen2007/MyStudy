

```
impl Solution {
    pub fn backspace_compare(s: String, t: String) -> bool {
        let mut v_s = Vec::<char>::new();
        let mut v_t = Vec::<char>::new();
        let mut s = s;
        let mut t = t;
        let mut back = 0;
        for c in s.chars().rev() {
            if back == 0 {
                if c != '#' {
                    v_s.push(c);
                } else {
                    back += 1;
                }
            } else {
                if c != '#' {
                    back -= 1;
                } else {
                    back += 1;
                }
            }
        }
        back = 0;
        for c in t.chars().rev() {
            if back == 0 {
                if c != '#' {
                    v_t.push(c);
                } else {
                    back += 1;
                }
            } else {
                if c != '#' {
                    back -= 1;
                } else {
                    back += 1;
                }
            }
        }
        println!("{:?}", v_s);
        println!("{:?}", v_t);
        v_s == v_t
    }
}
```
