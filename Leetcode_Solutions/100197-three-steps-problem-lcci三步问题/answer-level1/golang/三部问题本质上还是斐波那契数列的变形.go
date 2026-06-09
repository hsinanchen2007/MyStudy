### 解题思路
动态规划，状态转移方程，注意大数，有点坑

### 代码

```golang
func waysToStep(n int) int {
    if n == 0 {
        return 1
    }
    if n < 3 {
        return n 
    }
    if n == 3 {
        return 4
    }
    a := make([]int,n)
    a[0] = 1
    a[1] = 1
    a[2] = 2
    a[3] = 4
    for i := 3; i < n; i++ {
        a[i] = (a[i-1]%1000000007 + a[i-2]%1000000007 + a[i-3]%1000000007)%1000000007
    }
    return (a[n-1] + a[n-2] + a[n-3])%1000000007
}
```