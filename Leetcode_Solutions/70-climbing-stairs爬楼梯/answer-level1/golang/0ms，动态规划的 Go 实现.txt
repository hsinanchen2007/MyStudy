
![image.png](https://pic.leetcode-cn.com/a04d88c63cc3ca85b2512a71519048caa6e1629b2127d5eea799cc2d3a79e929-image.png)

自己写了个递归超时，然后参考官方题解写了记忆化递归和动态规划的 Go 实现，供各位参考。

递归
```
var cnt int = 0

func climb(curlevel int, sumlevel int) {
    if curlevel > sumlevel {
        return 
    } else if curlevel == sumlevel {
        cnt++
        return 
    }
    climb(curlevel+1, sumlevel)
    climb(curlevel+2, sumlevel)
}

func climbStairs(n int) int {
    cnt = 0
    climb(0,n)
    return cnt
}
```


记忆化递归
```
func climb(curlevel int, sumlevel int, cnt_nums []int) int {    // 递归所有情况
    if curlevel > sumlevel {                // 停止条件
        return 0
    } else if curlevel == sumlevel {
        return 1
    }
    if cnt_nums[curlevel] > 0 {
        return cnt_nums[curlevel]   // 已经计算过了
    }
    cnt_nums[curlevel] = climb(curlevel+1, sumlevel, cnt_nums) + climb(curlevel+2, sumlevel, cnt_nums)
    return cnt_nums[curlevel]
}

func climbStairs(n int) int {
    cnt_nums := make([]int, n)
    cnt := climb(0, n, cnt_nums)
    return cnt
}
```

动态规划
```
func climbStairs(n int) int {
    dp := make([]int, n+1)
    if n>=1 {
        dp[1] = 1
    }
    if n>=2 {
        dp[2] = 2
    }
    for i:=3; i<=n; i++ {
        dp[i] = dp[i-1] + dp[i-2]
    }
    return dp[n]
}
```