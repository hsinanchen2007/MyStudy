![image.png](https://pic.leetcode-cn.com/0ee2ef67d6dce7e4eb186fd7d64d098dd5f908c79ec725ae8a517462e5bb91d2-image.png)


### 代码

```golang
var dp func(x, y int) int

func uniquePathsWithObstacles(obstacleGrid [][]int) int {
    mem := map[string]int{}

    m := len(obstacleGrid)
    n := len(obstacleGrid[0])

    dp = func(x, y int) int {
        k := K(x, y)

        // exist
        if v, ok := mem[k]; ok {
            return v
        }

        if obstacleGrid[x][y] == 1 {
            mem[k] = 0
            return 0
        }

        if x == 0 && y == 0 {
            return 1
        }

        if x == 0 {
            mem[k] = dp(x, y - 1)
            return mem[k]
        }

        if y == 0 {
            mem[k] = dp(x - 1, y)
            return mem[k]
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