### 解题思路
此处撰写解题思路

### 代码

```golang
func fib(N int) int {
    a := 0
    b := 1
    for i := 0; i < N; i++{
       tmp := a
       a = b
       b = (tmp + b) % 1000000007
    }
    return a
}


```