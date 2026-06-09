```go
func fib(N int) int {
    if N == 0{
        return 0
    }
    if N <= 2 {
        return 1
    }
    n1, n2 := 1, 1  // n1为n-1，n2为n-2
    for i := 3; i < N; i++ {
        n1, n2 = n1+n2, n1
    }
    return n1 + n2
}
```
