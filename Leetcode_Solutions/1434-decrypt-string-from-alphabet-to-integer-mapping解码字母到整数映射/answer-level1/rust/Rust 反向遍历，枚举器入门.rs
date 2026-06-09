```rust
// 字符类型 char 可以转换成数字， 也就是其 codepoint 的值
const ascii_a: i32 = 'a' as i32;

impl Solution {
    pub fn freq_alphabets(s: String) -> String {
        // 首先用 .chars() 方法将字符串转换成一个枚举器，然后反转
        // 这里没有开始实际计算，因为枚举器是 lazy 的
        let mut iter = s.chars().rev();

        // 用一个 vector 来保存结果
        let mut r = vec![];

        // 开始循环，选择使用 .next() 方法手动从枚举器中取出元素
        // 这样方便我们适应有 '#' 的情况
        loop {
            match iter.next() {
                None => {
                    break;
                },
                Some(c) => {
                    if c == '#' {
                        // 有 '#' 号，取出两个字符，再转换成对应的数字
                        // 注意数字和 codepoint 是不一样的
                        let a = iter.next().unwrap().to_digit(10).unwrap() as i32;
                        let b = iter.next().unwrap().to_digit(10).unwrap() as i32;
                        r.push(b*10+a);
                    } else {
                        let a = c.to_digit(10).unwrap() as i32;
                        r.push(a);
                    }
                }
            }
        }
        // println!("{:?}", r);
        // 最后将 codepoint 转换成字符
        r.iter().rev().map(|&x| (x-1+ascii_a) as u8 as char).collect::<String>()
    }
}
```

执行消耗 0ms， 2.1mb