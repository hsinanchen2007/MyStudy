基本计算器 II

```
func calculate(s string) int {
    numstr := "0"
    stack := []int{0}
    op := []byte{'+'}
    for i := 0; i < len(s); i++ {
        if s[i] >= '0' && s[i] <= '9' {
            numstr += string(s[i])
        }
        if i == len(s)-1 || '+' == s[i] || '-' == s[i] || '*' == s[i] || '/' == s[i] {
            num, err := strconv.Atoi(numstr)
            if err != nil {
                break
            }
            devidor := stack[len(stack)-1]
            stack  = stack[:len(stack)-1]
            if '*' == op[len(op)-1] {
                stack = append(stack, devidor*num)
            } else if '/' == op[len(op)-1] {
                stack = append(stack, devidor/num)
            } else if '+' == op[len(op)-1] {
                stack = append(stack, devidor)
                stack = append(stack, num)
            } else if '-' == op[len(op)-1] {
                stack = append(stack, devidor)
                stack = append(stack, -num)
            }
            op = op[:len(op)-1]
            op = append(op, s[i])
            numstr = ""
        }
    }

    res := 0
    for _,v := range(stack) {
        res += v 
    }
    return res
}
```
