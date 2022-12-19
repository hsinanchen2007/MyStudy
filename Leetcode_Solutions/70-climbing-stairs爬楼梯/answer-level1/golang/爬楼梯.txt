### 解题思路
类似斐波那契数列
Fib(n)=Fib(n−1)+Fib(n−2)
### 代码

```golang
func climbStairs(n int) int {
    if n == 1 {
        return 1
    }

    f,s := 1,2
    for i := 3; i <= n; i++ {
        t := f + s
        f = s
        s = t
    }

    return s
}
```