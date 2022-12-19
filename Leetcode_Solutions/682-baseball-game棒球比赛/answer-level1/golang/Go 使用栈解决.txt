### 解题思路
此处撰写解题思路

### 代码

```golang
//注意 得分可能为负
func calPoints(ops []string) int {
    var stack []int
    
    for _,x:=range ops {
        s := string(x)
       if ok:=strings.Contains("CD+",s);!ok {
           stack = append(stack,str2int(s))
       }else if "+" == s {
           length := len(stack)
           if length == 0 {
               stack =append(stack,0)
           }else if length == 1 {
               stack =append(stack,stack[0])
           }else {
               stack =append(stack,stack[length-1]+stack[length-2])
           }
       }else if "D" == s {
          length := len(stack)
          if length == 0 {
              stack =append(stack ,0)
          }else {
              stack = append(stack,2*stack[length-1])
          }
       }else if "C" == s {
           length := len(stack)
           if length > 0 {
               stack = stack[:length-1]
           }
       }
    }

    sum := 0
    for _,y:=range stack {
        sum+=y
    }

   return sum
}

func str2int(s string) int {
    i,_:=strconv.Atoi(s)
    return i
}
```