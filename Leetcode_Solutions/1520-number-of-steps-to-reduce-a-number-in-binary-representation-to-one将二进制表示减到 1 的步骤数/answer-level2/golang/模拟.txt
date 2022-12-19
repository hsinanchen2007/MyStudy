### 解题思路

#### 思路一：转化为10进制，进行模拟(超时)

##### 代码：
```golang
func numSteps(s string) int {
    num := convertToDecimal(s)
    res := 0
    for num != 1{
        if num % 2 == 0 {
            num /= 2
        } else {
            num += 1
        }
        res++
    }
    return res
}

func convertToDecimal(s string) int {
    n := len(s)
    res := 0
    for i := 0; i < n; i++{
        res += int(math.Exp2(float64(n-1-i))) * int(s[i]-'0')
    }
    return res
}

```

#### 思路二：直接操作字符串（通过）

##### 代码：
```golang
func numSteps(s string) int {
    res := 0
    for s != "1" {
        n := len(s)
        if s[n-1] == '0' {
            s = s[:n-1]
        } else {
            s = plusOne(s)
        }
        res++
    }
    return res
}

func plusOne(s string) string {
    flag := 0
    c := []byte(s)
    n := len(s)
    for i := n-1; i >= 0; i--{
        if s[i] == '0' {
            c[i] = '1' 
            flag++
        } else {
            c[i] = '0'
        }
        if flag == 1 {
            return string(c)
        }
    }
    //全1
    return "1" + string(c)
}
```