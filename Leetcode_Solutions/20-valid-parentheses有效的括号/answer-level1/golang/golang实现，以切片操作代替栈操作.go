### 解题思路
如果为括号的左半部分进栈，如果栈顶元素与右半部分匹配，出栈。否则报错

### 代码

```golang
//这个是栈的结构，但是golang本身没有栈结构，利用切片来模拟栈结构
func isValid(s string) bool {
    var stack []byte

    //如果为括号的左半部分进栈，如果栈顶元素与右半部分匹配，出栈。否则报错
    for i:= 0;i< len(s);i++{              
        if s[i] == '(' || s[i] == '{' || s[i] == '['{
            stack = append(stack,s[i])
        }else if len(stack) == 0 && (s[i] == ')' || s[i] == '}' || s[i] == ']'){
            return false
        }else if stack[len(stack)-1] == '(' && s[i] == ')'{
            stack = stack[:len(stack)-1]
        }else if stack[len(stack)-1] == '{' && s[i] == '}'{
            stack = stack[:len(stack)-1]
        }else if stack[len(stack)-1] == '[' && s[i] == ']'{
            stack = stack[:len(stack)-1]
        }else{
            return false
        }
    }

    //判断是否括号成对出现
    if len(stack) != 0{
        return false
    }
    return true
}
```