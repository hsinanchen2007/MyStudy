![image.png](https://pic.leetcode-cn.com/16a1e482b408b01c07de0913cece833c6ebd241c78524e3f5b224a8931f89e9f-image.png)


### 代码

```golang
var dp func(x, y int) int

func uniquePaths(m int, n int) int {
    mem := map[string]int{}

    dp = func(x, y int) int {
        k := K(x, y)

        // exist
        if v, ok := mem[k]; ok {
            return v
        }

        if x == 0 || y == 0 {
            mem[k] = 1
            return 1
        }

        mem[k] = dp(x - 1, y) + dp(x, y - 1)
        return mem[k]
    }

    return dp(m - 1, n - 1)
}

func K(x, y int) string {
    return fmt.Sprint(x, y)
}
```