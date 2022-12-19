### 解题思路
在符号匹配的题目，很容易想到使用栈来进行匹配。那么问题就在于如何使用栈的匹配来进行最长字符串的匹配。

当使用栈完成匹配后，我们得到的剩余的元素均是“不能匹配”的字符，那么在其中间的字符就是得到了匹配并pop出栈的字符。那么，如果知道这些“不能匹配”字符的下标，那么我们就可以通过下标的比较来知道中间的字符个数，两个相邻“不能匹配”的字符下标差值最大的地方他们中间的可匹配字符就是最大的（必要性，可以通过反证得出充分性）。这里需要注意最长的可匹配字符串也可以在头尾，所以在比较时需要添加 -1 和s.len()。

记录下标的方法可以是构建一个结构体,用结构体来进行匹配，最后比较时加上两个首位标志即可。
```rust
struct char_with_index {
    index:usize,
    ch:char
}
```

笔者因为偷懒，使用两个stack分别记录字符和下标，并同步增减的方式。这样的好处是可以在下标栈中直接添加首位标志，比较时比较简便。


初学Rust，代码有不规范的地方，希望不吝指出，多谢！

### 代码

```rust
impl Solution {
    pub fn longest_valid_parentheses(s: String) -> i32 {
        let s_bytes = s.as_bytes();
        let mut stack_s: Vec<u8> = Vec::new(); 
        let mut stack_no: Vec<i32> = Vec::new(); 
        stack_no.push(-1);
        let mut result: i32 = 0;
        for i in 0..(s_bytes.len()) {
            if stack_s.len() == 0 || ((stack_s[stack_s.len() - 1] == s_bytes[i]) || (stack_s[stack_s.len() - 1] != String::from("(").as_bytes()[0])) {
                stack_s.push(s_bytes[i]);
                stack_no.push(i as i32);
            } else {
                stack_s.pop();
                stack_no.pop();
            }
        }
        stack_no.push(s_bytes.len() as i32);
        for i in 1..stack_no.len() {
            if stack_no[i] - stack_no[i - 1] > result {
                result = stack_no[i] - stack_no[i - 1] - 1;
            }
        }
        result
    }
}
```