遍历一遍字符串,并为每个字符计数,计数完毕时拼接到新字符串的尾部.

如 "abbccd"

构造一个新的空字符串后
首先设置标志位 count, 和当前字符 current.

遍历字符串每一个字符
每当 current 字符与 当前遍历的字符相同时, 数量加一
不同时,则保存 current 字符和他的个数到新字符串中.并更新 current 为当前字符, count 置位 1(因为遇到了一个新的字符)

遍历完毕之后, 注意到,最后一次统计的字符和个数还未加入新字符串.加入.

最后判断是否 新字符串更短, 返回更短的字符串的所有权.

### 代码

```rust
impl Solution {
pub fn compress_string(s: String) -> String {
    let mut new = String::new();
    let mut count = 0;
    let mut character = ' ';
    for i in s.chars() {
        if i == character {
            count = count+1;
            continue;
        }
        if count != 0 {
            new.push(character);
            new.push_str(&count.to_string());
        
            character = i;
            count =1;
                continue;
        }

        character = i;
        count = count+ 1;
    }

    new.push(character);
    new.push_str(&count.to_string());
    println!("{}-{}",s,new);
    if new.chars().count() >= s.chars().count() {
        return s
    }
    new
}
}
```