1. 递归，时间复杂度O(2^n)
```
func fib(N int) int {
    if N < 0 {
        return 0       
    }
    if N <= 1 {
        return N
    }

    return fib(N-1) + fib(N-2)
}
```
2.动态规划(动态递推)，时间复杂度O(n)，空间复杂度O(n)) 
```
func fib(N int) int {
    if N < 0 {
        return 0       
    }
    if N <= 1 {
        return N
    }
    fibArr := make([]int, N+1)
    fibArr[0], fibArr[1] = 0, 1
    for i:=2; i<N+1; i++ {
        fibArr[i] = fibArr[i-1] + fibArr[i-2]
    }
    return fibArr[N]
}
```
3.动态规划(动态递推)，时间复杂度O(n)，空间复杂度O(1)) 
```
func fib(N int) int {
    if N <= 0 {
        return 0
    }
    if N <= 2 {
        return 1
    }

    prePre, pre := 1, 1
    for i:=3; i< N; i++ {
        prePre, pre = pre, prePre+pre
    }

    return pre + prePre
}
```


