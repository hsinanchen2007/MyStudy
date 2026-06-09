![image.png](https://pic.leetcode-cn.com/0dde746eeab8af852569344fa7fc1852fd6d9d1af9c6b6c12de99f7c4ba159fb-image.png)

这类加法题最重要的就是注意溢出，字符串数字要多大就有多大。

```Rust
impl Solution {
    pub fn add_binary(mut a: String, mut b: String) -> String {
        let mut carry = 0;
        let mut res = String::new();
        loop {
            let (n1, n2) = (a.pop(), b.pop());
            
            if n1 == None && n2 == None { break; }
            
            let mut sum = carry;
            if let Some(x) = n1 {
                    sum += x.to_digit(2).unwrap();
            }
            if let Some(x) = n2 {
                sum += x.to_digit(2).unwrap();
            }
            
            carry = sum / 2;
            res.insert_str(0, &(sum % 2).to_string());
        }
        if carry > 0 { res.insert_str(0, &carry.to_string()); }
        res
    }
}
```


