### 解题思路
此处撰写解题思路
为啥这么慢啊
### 代码

```golang
func fizzBuzz(n int) []string {

    var str []string
    for i := 1; i <= n; i++ {
        if (i % 15 == 0) {
            str = append(str,"FizzBuzz")
        }else if (i % 3 == 0) {
            str = append(str,"Fizz")
        }else if (i % 5 == 0) {
            str = append(str,"Buzz")
        }else {
            str = append(str,strconv.Itoa(i))
        }
    }
    return str
}
```