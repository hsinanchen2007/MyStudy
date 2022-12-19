### 解题思路
遇到非#入栈，遇到#，将栈内的数据出栈。如果此时栈为空，则跳过，继续执行

### 代码

```golang
func backspaceCompare(S string, T string) bool {
 
 s:=parseString(S)
 
 t:=parseString(T)

 return s == t



}

func parseString(S string) string{
    var stack []rune
    for _,v := range S {
        s := string(v)
        if s != "#" {
            stack = append(stack,v)
        }else {
            if len(stack) ==0 {
               continue
            }else {
                stack = stack[:len(stack)-1]
            }
        }
    }
      if len(stack)==0 {
          return ""
      }else {
          return string(stack)
      }

}
```