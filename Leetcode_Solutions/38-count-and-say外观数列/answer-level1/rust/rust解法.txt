### 解题思路
一行一行的生成法

### 代码

```rust
use std::char::from_digit;
impl Solution {
    pub fn count_and_say(n: i32) -> String {
//    t38
    if n == 1{
        let mut ret = "1".to_string();
        return ret;
    }
    let mut s = vec![];
    for i in 0..n{
        if s == vec![]{
            s = vec!['1']
        }
        else {
            let mut res_num = vec![];
            let mut pre_num = '0';
            let mut pre_sum = 0;
            for i in s{
                if pre_num!='0'{
                    if i != pre_num{
                        let mut u = pre_sum as u32;
                        res_num.push(from_digit(u, 10).unwrap());
                        res_num.push(pre_num);
                        pre_num = i;
                        pre_sum = 1;
                    }
                    else {
                        pre_num = i;
                        pre_sum += 1
                    }
                }
                else {
                    pre_num = i;
                    pre_sum = 1; }
            }
            let mut u = pre_sum as u32;
            res_num.push(from_digit(u, 10).unwrap());
            res_num.push(pre_num);
            s = res_num;
        }
    }
    let mut res = "".to_string();
    for i in s{
        res += &i.to_string();
    }
    return res;
}
}
```