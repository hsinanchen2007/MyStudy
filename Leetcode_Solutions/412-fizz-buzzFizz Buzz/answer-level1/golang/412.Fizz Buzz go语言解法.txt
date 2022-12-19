### 解题思路

很简单的一道题，循环判断就行了。

### 代码

```golang
func fizzBuzz(n int) []string {
    var res []string
    for i := 1;i <= n;i++ {
        if i % 3 == 0 && i % 5 == 0 {
            res = append(res,"FizzBuzz")
        }else if i % 3 == 0 {
            res = append(res,"Fizz")
        }else if i % 5 == 0 {
            res = append(res,"Buzz")
        }else {
            res = append(res,fmt.Sprintf("%d",i))
        }
    }
    return res
}
```