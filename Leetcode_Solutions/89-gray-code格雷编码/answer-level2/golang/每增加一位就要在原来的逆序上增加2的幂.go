### 解题思路
动态规划

### 代码

```golang
func grayCode(n int) []int {
    var res []int
    // 默认只有一个0
    res = append(res, 0)
    if n == 0 {
        return res
    }
    if n >= 1 {
        res = append(res, 1)
    }
    base := 1
    for i := 2; i <= n; i++ {
        // 反转前面的结果，在前面加1
        l := len(res)
        base = base * 2
        for j := l - 1; j >= 0; j-- {
            res = append(res, res[j] + base)
        }
    }
    return res
}

func power(n, k int) int {
    if k == 0 {
        return 1
    }
    if k == 1 {
        return n
    }
    if k % 2 == 0 {
        return power(n * n, k / 2)
    } else {
        return power(n * n, k - 1 / 2) * n
    }
}
```