```
func isValid(s string) bool {
    
    // 这里用切片来模拟栈，用于暂存左括号
    stack := []byte{}
    // 定义配对的字符
    matchMap := map[byte]byte{'(': ')', '[': ']', '{': '}'}

    for _, v := range s {
        // 遇到左括号就入栈
        if v == '(' || v == '[' || v == '{' {
            stack = append(stack, byte(v))
        } else if (len(stack) == 0) {  // 如果栈为空（没有左括号）的情况下，遇到右括号，则肯定无法配对，直接返回false
            return false
        } else {  // 遇到右括号的时候，从栈中pop出一个左括号进行比对
            pop := stack[len(stack) - 1]
            if match, ok := matchMap[pop]; ok && match == byte(v) {
                stack = stack[0: len(stack) - 1]
            } else {
                return false
            }
        }
    }
    
    // 遍历完字符串，检查栈是否为空，如果没有左括号残留了，说明完全匹配了
    if len(stack) == 0 {
        return true
    }
    return false
}
```
