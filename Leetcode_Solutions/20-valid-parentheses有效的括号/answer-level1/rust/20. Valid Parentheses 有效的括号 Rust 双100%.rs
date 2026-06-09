![图片.png](https://pic.leetcode-cn.com/2f8d437bab78e4d597e4cd14aa907264e7cede60472d006e5678b287224e8eb9-%E5%9B%BE%E7%89%87.png)
``` rust
use std::collections::VecDeque;
impl Solution {
    pub fn is_valid(s: String) -> bool {
        if(s == "") {return true;}
        let mut dq : VecDeque<char> = VecDeque::new();
        dq.push_front('#'); // to prevent special cases such as: )()
        for c in s.chars() {
            if(c == ')') {
                if(dq[0] != '(') {
                    return false;
                } else {
                    dq.pop_front();
                }
            } else if(c == ']') {
                if(dq[0] != '[') {
                    return false;
                } else {
                    dq.pop_front();
                }
            } else if(c == '}') {
                if(dq[0] != '{') {
                    return false;
                } else {
                    dq.pop_front();
                }
            } else {
                dq.push_front(c);
            }
        }
        if(dq[0] != '#') {
            return false;
        }
        return true;
    }
}
```
