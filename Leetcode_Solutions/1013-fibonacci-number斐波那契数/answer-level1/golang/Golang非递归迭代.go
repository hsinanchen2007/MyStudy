```
func fib(N int) int {
    if N == 0{
        return 0
    }
    if N == 1{
        return 1
    }
    a , b := 0, 1 
    for i:= 2; i <= N;i++{
        a, b = b, a + b
    }
    return b
}
```