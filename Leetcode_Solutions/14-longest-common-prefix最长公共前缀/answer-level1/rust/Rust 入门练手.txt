学习中，比c++难写好多啊

```
impl Solution {
    pub fn longest_common_prefix(strs: Vec<String>) -> String {
        let mut result = String::new();
        let mut l = 0;
        let mut flag = false;
        if strs.len() == 0 {
            return result;
        }
        loop{
            let c = strs[0].chars().nth(l);
            for iter in &strs {
                if (iter.chars().nth(l) != c) {
                    flag = true;
                    break;
                }
            }
            if flag {
                break;
            }
            match c{
                Some(value)
                    => result.push(value),
                None
                    => break,
            }
            l += 1;
        }
        result
    }
}
```