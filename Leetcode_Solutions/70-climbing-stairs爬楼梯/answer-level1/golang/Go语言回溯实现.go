递推公式f(n) = f(n-1) + f(n-2)  

由于一次可以走一级或者两级台阶，所以到某个台阶n的走法等于：走到台阶n-1的走法(最后一次走一级台阶上到n)，加上走到台阶n-2的走法(最后一次走两级台阶上到n)。  

递推的过程中会有大量的重复计算，这里使用一个map来记录已经确定了有多少种走法的子问题。  


```

func climbStairs(n int) int {
    m := make(map[int]int)
    return recursionHandler(n, m)
}

func recursionHandler(n int, m map[int]int) int {
    if n == 1 {
        m[n] = 1
        return 1
    }
    if n == 2 {
        m[n] = 2
        return 2
    }

    var x, y int
    var ok bool
    x, ok = m[n-1]
    if !ok {
        x = recursionHandler(n-1, m)
    }
    y, ok = m[n-2]
    if !ok {
        y = recursionHandler(n-2, m)
    }
    m[n] = x + y
    return x + y
}

```