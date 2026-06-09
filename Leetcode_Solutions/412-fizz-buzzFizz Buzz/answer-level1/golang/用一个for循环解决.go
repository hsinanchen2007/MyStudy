### 解题思路

按照题目要求的一步步写，读取`n`的值，然后开始一个`for`循环在里面一个个判断满足的结果，注意要先将`既是3又是5的倍数`这一条件进行优先判断。

### 代码

```golang
func fizzBuzz(n int) []string {
    var re []string
    for i:=1;i<=n;i++ {
        if (i%3 == 0 && i%5 == 0) {
            re = append(re,"FizzBuzz")
        } else if (i%5 == 0) {
            re = append(re,"Buzz")
        } else if (i%3 == 0) {
            re = append(re,"Fizz")
        } else {
            re = append(re,strconv.Itoa(i))
        }
    }
    return re
}
```