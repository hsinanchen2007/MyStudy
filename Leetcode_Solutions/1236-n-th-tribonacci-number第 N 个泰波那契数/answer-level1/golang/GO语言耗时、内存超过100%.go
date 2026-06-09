0ms  2MB

```
// 非递归解法
func tribonacci(n int) int {
    if n <= 1 {
        return n
    }
    if n == 2 {
        return 1
    }
    var data = make([]int, n+1)
    data[0] = 0
    data[1] = 1
    data[2] = 1
    for i := 3; i <= n; i++ {
        data[i] = data[i-1] + data[i-2] + data[i-3]
    }
    return data[n]
}
```