### 解题思路 
使用栈来进行匹配，左括号全部如栈，右括号每次拿栈顶元素进行匹配，如果匹配弹出栈顶。
如果不匹配，则直接返回false。
其中两个小细节
1、最后如果栈还大于0，那就是false。
2、如果是右括号，从栈中取元素为空，则也是false。

### 代码

```golang
func isValid(s string) bool {
    compareMap := map[string]string{
        ")" : "(",
        "}" : "{",
        "]" : "[",
    }
    l := list.New()
    for index := 0; index < len(s); index++ {
        charStr := string(s[index])
        if charStr == "(" || charStr == "{" || charStr == "[" {
            l.PushBack(charStr)
        }else{
            lastStr := l.Back()
            if lastStr == nil {
                return false
            }
            if lastStr.Value == compareMap[charStr]{
                l.Remove(lastStr)
            }else{
                return false
            }
        }
    }
    if l.Len() > 0 {
        return false
    }

    return true
}
```