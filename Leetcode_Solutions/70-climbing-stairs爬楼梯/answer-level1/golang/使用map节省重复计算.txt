 
i为当前的台阶数
n为目标台阶数
memo用于存储已经存在的台阶

```go
func climbStairs(n int) int {
	memo := map[int]int{}

	return climb_Staris(0, n, memo)
}

func climb_Staris(i int, n int, memo map[int]int) int {
	if i > n {
		return 0
	}

	if i == n {
		return 1
	}

	// 存在就直接返回
	if memo[i] > 0 {
		return memo[i]
	}
	memo[i] = climb_Staris(i+1, n, memo) + climb_Staris(i+2, n, memo)

	return memo[i]
}
```
![image.png](https://pic.leetcode-cn.com/0d6ebcc9b52a57c94cfae5807ddc035f64e823b91804ab165a924c8f6f8ee64b-image.png)
