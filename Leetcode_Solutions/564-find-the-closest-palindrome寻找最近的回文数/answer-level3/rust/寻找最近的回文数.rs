### 解题思路
awsl
感觉rust的String操作太难了
方法都懂,...太难表达了， 写出来的代码都是火星语
还好过了
### 代码

```rust
impl Solution {
    pub fn nearest_palindromic(n: String) -> String {
        let len = n.len();
        let tt = n.parse::<i64>().unwrap();
        if tt <= 11 {
            if tt < 10 {
                return (tt - 1).to_string();
            }
            return "9".to_string();
        }
        let harf = (len as f32 / 2.).ceil() as usize;
        let rnum = n.parse::<i64>().unwrap();
        
        let num2 = n[0..harf].parse::<i64>().unwrap();
        let num1 = num2 + 1;
        let num3 = num2 - 1;

        let mut res: Vec<i64> = Vec::new();

        let mut s = String::with_capacity(len);
        s.insert_str(0, &n[0..harf]);
        res.push(Solution::fc(&mut s, len));
        
        let t = num1.to_string();
        if t.len() == harf {
            let mut s = String::with_capacity(len);
            s.insert_str(0, &*t);
            res.push(Solution::fc(&mut s, len));
        } else {
            res.push(10i64.pow(len as u32) + 1);
        }

        let t = num3.to_string();
        if t.len() == harf {
            let mut s = String::with_capacity(len);
            s.insert_str(0, &*t);
            res.push(Solution::fc(&mut s, len));
        } else {
            res.push(10i64.pow(len as u32 - 1) - 1);
        }
        println!("{:?}", res);
        let mut min: i64 = res.iter().max().unwrap().clone();
        for i in res {
            if i == rnum {
                continue;
            }
            let t = (i - rnum).abs();
            if t < (min - rnum).abs() || (t == (min - rnum).abs() && i < min) {
                min = i;
            }
        };
        min.to_string()
    }

    fn fc(s: &mut String, len: usize) -> i64 { // 获取回文数
        let v = unsafe {s.as_mut_vec()};
        let mut v = v.clone();
        if len & 1 == 1 {
            v.pop();
        }
        v.reverse();
        if let Ok(x) = String::from_utf8(v) {
            s.push_str(&*x);
        }
        println!("{:?}", s);
        s.parse().unwrap()
    }
}
```