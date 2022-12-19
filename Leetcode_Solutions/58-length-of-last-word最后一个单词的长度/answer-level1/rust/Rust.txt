
![image.png](https://pic.leetcode-cn.com/cdec30c010cc9bd7f1e5b59c5971b309488a6a13d7a499649ec9e9bf9d2028ae-image.png)

<br>
<br>

1. 倒着数，统计字符长度。需要注意最后有空格情况，这里加入一个判断，如果还没有统计字符，则跳过，如果统计了，则退出。直到最后一个字符。
```Rust
impl Solution {
    pub fn length_of_last_word(mut s: String) -> i32 {
        let mut count = 0i32;
        loop {
            let ch = s.pop();
            if None == ch { break; }
            if ch == Some(' ') && count == 0 { continue; }
            if ch == Some(' ') { break; }
            count += 1;
        }
        count
    }
}
```

2. 先去掉外面空白，再用通过空格分段，直接取最后一个单词的长度即可。
```Rust
impl Solution {
    pub fn length_of_last_word(s: String) -> i32 {
        let v:Vec<&str> = s.trim().rsplit(' ').collect();
        if v.is_empty() { 0i32 }
        else { v[0].len() as i32 }
    }
}
```

