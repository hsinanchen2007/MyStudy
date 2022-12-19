
![image.png](https://pic.leetcode-cn.com/60624db84d679f15c578e47c370f17f823fe06c2d37081840ef574265de4f756-image.png)


方法一：用切片模拟栈，使用 switch 
```
func handle(stack []string, x string) (bool, []string) {
    if(len(stack)==0) { // 栈空了，返回错误
        return false, stack
    }    
    if(stack[len(stack)-1]==x) { // 和栈顶元素匹配，匹配成功，出栈
        stack = stack[0:len(stack)-1]
        return true, stack
    } else {    // 匹配失败，返回错误
        return false, stack
    }
}

func isValid(s string) bool {
    stack := []string{}
    var ok bool
    for _,x := range(s) {
        switch x {
            case '(':fallthrough
            case '[':fallthrough
            case '{':stack=append(stack,string(x))
            case ')':
            if ok,stack = handle(stack,"("); !ok {
                return false
            }
            case ']':
            if ok,stack = handle(stack,"["); !ok {
                return false
            }
            case '}':
            if ok,stack = handle(stack,"{"); !ok {
                return false
            }
        }
    }
    if (len(stack)==0) {
        return true
    } else {
        return false
    }
}
```
这个代码太长了，而且不够优雅，于是改进一下。

方法二：用切片模拟栈，用 map 保存对应的前括号，switch => if else
```
func isValid(s string) bool {
    stack := []string{}
    // 后括号映射表
    frontBracket := map[string]string{ ")":"(", "]":"[", "}":"{" }

    for _, x := range s {
        if x=='(' || x=='[' || x=='{' {     // 遇到前括号，入栈
            stack = append(stack,string(x))     
        } else if x==')' || x==']' || x=='}' {    // 遇到后括号，判断
            if len(stack)!=0 && stack[len(stack)-1] == frontBracket[string(x)] { // 栈非空，和栈顶元素匹配，匹配成功，出栈
                stack = stack[0:len(stack)-1]
            } else {    // 栈空或者匹配失败，返回错误
                return false
            }
        }
    }
    if (len(stack)==0) {
        return true
    } else {
        return false
    }
}
```