我觉得Rust写的还是挺顺的。

```
impl Solution {
    pub fn plus_one(digits: Vec<i32>) -> Vec<i32> {
        let mut digits = digits;
        let mut res = vec![];
        let mut flag = true;
        loop {
            match digits.pop() {
                Some(mut current) => {
                    if flag { current += 1 }
                    if current >= 10 {
                        flag = true;
                        current -= 10;
                    } else {
                        flag = false;
                    }
                    res.push(current);
                },
                None => {
                    if flag {res.push(1);}
                    break;
                },
            }
        }
        res.reverse();
        res
    }
}
```
