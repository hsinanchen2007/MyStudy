### 解题思路
- 使用“滑动窗口“来解题
- 考虑到`utf-8`编码的字符串，使用`s.char_indices`迭代器遍历、获取字符`c`和字符在字符串中的位置`place`
- `left`表示窗口的左边，起始为0；`place`表示窗口的右边，子字符串的长度为`place - left + 1`
- 在`HashMap`中查找`c`是否在窗口中，也就是查找`c`的值`v`是否不小于`left`
- 如果存在：`v>=left`，弹出重复的字符：`left = v + 1`
- 如果不存在，在`HashMap`插入`<c, place>`记录窗口的右边`place`


### 代码

```rust
impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
         use std::collections::HashMap;
         let mut check_char = HashMap::new();
         let mut left = 0;
         let mut substr_len = 0;
 
         for (place, c) in s.char_indices() {
             check_char
                 .entry(c)
                 .and_modify(|v| {
                     if *v >= left {
                         left = *v + 1
                     }
                     *v = place
                 })
                 .or_insert(place);
             if substr_len <= place - left {
                 substr_len = place - left + 1
             }
         }
         substr_len as i32
     }
}
```