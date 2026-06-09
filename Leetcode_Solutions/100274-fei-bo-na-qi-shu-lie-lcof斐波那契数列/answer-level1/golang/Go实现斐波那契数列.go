

```golang
func fib(N int) int {
    if N ==0{
        return 0
    }
    if N ==1{
        return 1
    }
    one := 1
    two := 0
    result :=0
    for i:=2;i<=N;i++{
        result = (one+two)%1000000007
         two=one
        one =result
    }
    return result
}
```

```
func fib(N int) int {
    if N == 0{
        return 0
    }
    if N == 1{
        return 1
    }
    dp := make([]int,N+1)
    dp[1] = 1
    for i:=2;i<=N;i++{
        dp[i] = (dp[i-1]+dp[i-2])%1000000007
    }
    return dp[N]
}
```
