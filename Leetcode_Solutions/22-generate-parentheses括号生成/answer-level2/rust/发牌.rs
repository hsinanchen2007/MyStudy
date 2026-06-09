```
impl Solution {
    // left, right: 剩余括号
    fn recur(s: String, left: i32, right: i32, ret: &mut Vec<String>) {
        if left > right{
            return;
        }
        if right == 0 {
            ret.push(s);
            return;
        }
        if left > 0 {
            Self::recur(format!("{}{}", s, '('), left - 1, right, ret);
        }
        if right > 0 {
            Self::recur(format!("{}{}", s, ')'), left, right - 1, ret);
        }

    }
    pub fn generate_parenthesis(n: i32) -> Vec<String> {
        let mut ret = vec![];
        Self::recur(String::new(), n, n, &mut ret);
        ret
    }
}
```
