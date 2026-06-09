### 解题思路
用一个栈存储遍历过的字符，如果当前字符为"([{"中的一个，则压入栈，如果当前字符为")]}"中的一个且与前一个字符匹配
则弹出栈顶，如果不匹配则可以提前终止遍历，判断字符不正确。最后如果栈内还有字符，则说明有不匹配的括号。

### 代码

```rust
impl Solution {
    pub fn is_valid(s: String) -> bool {
        let mut stack: Vec<char> = vec![];
        for ch in s.chars() {
            if stack.is_empty() {
                stack.push(ch);
            } else {
                match ch {
                    '(' | '[' | '{' => stack.push(ch),
                    ')' | ']' | '}' => {
                        if (ch == ')' && *stack.last().unwrap() == '(')
                            || (ch == ']' && *stack.last().unwrap() == '[')
                            || (ch == '}' && *stack.last().unwrap() == '{')
                        {
                            stack.pop();
                        } else {
                            break;
                        }
                    }
                    _ => (),
                }
            }
        }
        stack.is_empty()
    }
}
```