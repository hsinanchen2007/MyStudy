# 思考

## 方法一 斐波那契数列

1. 当n为1或2时，可以直接返回结果；其他情况都是根据前两个结果来计算出来的，所以只需要保存前两个结果。故时间复杂度是O(n)，空间复杂度是O(1)。[学习自一行](https://leetcode-cn.com/problems/climbing-stairs/solution/golangshi-xian-pa-lou-ti-by-pppobear/)

循环实现
```go
func climbStairs(n int) int {
	switch n {
	case 1:
		return 1
	case 2:
		return 2
	default:
		pre, cur := 1, 2 // pre存储前一个数,cur存储当前数
		for i := 2; i < n; i++ {
			pre, cur = cur, pre+cur
		}
		return cur
	}
}
```

- 设爬 `n` 个台阶有 `f(n)`  种可能：
  - 假设先爬 `1` 阶，剩下 `n-1`  阶有 `f(n-1)`  种可能；
  - 假设先爬 `2` 阶，剩下 `n-2` 阶有 `f(n-2)`  种可能，
  - 因此爬 `n` 阶可以转化为两种爬 `n-1` 阶问题之和： `f(n) = f(n-1) + f(n-2)` ；

- 不难看出，这就是 `斐波那契数列` 公式，此题可转化为求斐波那契数列第 `n` 项。[学习自jyd](https://leetcode-cn.com/problems/two-sum/solution/70-climbing-stairs-dong-tai-gui-hua-fei-bo-na-qi-s/)

```go
func climbStairs(n int) int {
    pre, cur := 1, 1
    for i := 0; i < n-1; i++ {
        pre, cur = cur, pre+cur
    }
    return cur
}
```

## 方法二 斐波那契公式

用递推公式学习[自灵魂画师牧码](https://leetcode-cn.com/problems/two-sum/solution/hua-jie-suan-fa-70-pa-lou-ti-by-guanpengchn/)

```go
func climbStairs(n int) int {
    sqrt5 := math.Sqrt(5)
    fibN := math.Pow((1+sqrt5)/2, float64(n+1)) - math.Pow((1-sqrt5)/2, float64(n+1))
    return int(math.Round(fibN / sqrt5))
}
```

## 方法三 动态规划

本问题其实常规解法可以分成多个子问题，爬第n阶楼梯的方法数量，等于 2 部分之和
   1. 爬上 n−1 阶楼梯的方法数量。因为再爬1阶就能到第n阶
   2. 爬上 n−2 阶楼梯的方法数量，因为再爬2阶就能到第n阶
所以我们得到公式 dp[n]=dp[n−1]+dp[n−2]
同时需要初始化 dp[0]=1 和 dp[1]=1
时间复杂度： O(n)

```go
func climbStairs(n int) int {
    dp := make([]int, n+1)
    dp[0] = 1
    dp[1] = 1
    for i := 2; i <= n; i++ {
        dp[i] = dp[i-1] + dp[i-2]
    }
    return dp[n]
}
```

## 方法四 递归实现
超出时间限制
设爬 n 个台阶有 f(n)  种可能：
- 假设先爬 1 阶，剩下 n-1 阶有 f(n-1)  种可能；
- 假设先爬 2 阶，剩下 n-2 阶有 f(n-2)  种可能，
因此爬 n 阶可以转化为两种爬 n-1 阶问题之和： f(n) = f(n-1) + f(n-2) ；

```go
func climbStairs3(n int) int {
    if n == 1 {
        return 1
    } else if n == 2 {
        return 2
    } else {
        return climbStairs3(n-1) + climbStairs3(n-2)
    }
}
```

优化实现

```go
func climbStairs(n int) int {
	if n < 2 {
		return 1
	}
	return climbStairsRecursive(n-1) + climbStairsRecursive(n-2)
}

func climbStairsRecursive(n int) int {
	first, second := 1, 1
	for i := 1; i < n; i++ {
		third := first + second
		first = second
		second = third
	}
	return second
}
```