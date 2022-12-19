### 解题思路
此处撰写解题思路

### 代码

```golang
func isValid(s string) bool {
    if len(s) == 0 {
        return true
    }
    if len(s) < 2 {
        return false
    }
    var (
        stack = []byte{}
    )
    for i := 0; i < len(s); i ++ {
        if len(stack) == 0 {
            stack =append(stack,s[i])
            continue
        }
        top := stack[len(stack)-1]
        temp := s[i]
        if (top == '(' && temp == ')') || (top == '{' && temp == '}') || (top == '[' && temp == ']') {
            stack = stack[:len(stack)-1]
        }else {
            stack = append(stack,temp)
        }
    }
    return len(stack) == 0
}
```