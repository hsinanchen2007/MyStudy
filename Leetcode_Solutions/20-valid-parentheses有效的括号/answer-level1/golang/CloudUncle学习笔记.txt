### 解题思路
使用数组模拟栈，先进后出

### 代码

```golang
func isValid(s string) bool {
    stack := []byte{}
    match := map[byte]byte{
        ')': '(',
        ']': '[',
        '}': '{',
    }
    for i:=0; i<len(s); i++ {
        switch s[i] {
        case '(', '[', '{':
            stack = append(stack, s[i])
        case ')', ']', '}':
            if len(stack)==0 || stack[len(stack)-1] != match[s[i]] {
                return false
            }
            stack = stack[:len(stack)-1]
        }
    }
    return len(stack)==0
}
```