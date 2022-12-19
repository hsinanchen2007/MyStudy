```
func fib(n int) int {
    var ( i = 0
    fibs = make([]int, 102))

    fibs[0] = 0
    fibs[1] = 1
    for i = 2; i <= n; i++ {
        fibs[i] = (fibs[i-2] + fibs[i-1])%1000000007
    }
    return fibs[n]
}
```
