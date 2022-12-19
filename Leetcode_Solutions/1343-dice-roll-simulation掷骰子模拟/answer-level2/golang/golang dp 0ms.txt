统计每个回合每个数字的连续次数，最后计算总和。

先来一张图，方便理解：
这里 `dp[2][1][0] = sum(dp[1][2]) + sum(dp[1][3]) + sum(dp[1][4]) + sum(dp[1][5]) + sum(dp[1][6]) = 5`，线太多影响体验就没有画。

![dis.gif](https://pic.leetcode-cn.com/3aae23a44981c9fdf2eadbd22fd7c71989413201e8618229fa48856cd36c925d-dis.gif){:width=500}
{:align=center}


我们通过一个二维数据 `dp[6][15]` 统计每一轮每个数字的连续情况。`dp[3][4]` 表示点数 3 连续 4 次的数字个数。
1. 首先，当 `n=1` 时，所有数字都是一样，且连续次数都是 1。
2. 当 `n=2` 时，就需要根据 rollMax 去计算。
	- 连续次数为 1 的时候很好理解，就是把其他点数当前的点数全部相加即可，对应代码为：
		```Go [-Go]
		for j := 0; j < 6; j++ {
			if i != j {
				tmp[i][0] = (tmp[i][0] + total[j]) % mod
			}
		}
		```
	- 连续次数为  时，只能取上一次连续次数为 1 的值，其他情况均不满足，对应代码为：
		```go [-Go]
		for j := 1; j < rollMax[i]; j++ { // 根据rollMax判断可以连续几次
			tmp[i][j] = dp[i][j-1]
		}
		```
3. 计算当次每个点数总和，方便下次计算。
4. 累加最后一次计算的总和。


完整代码：
```go [-Go]
func dieSimulator(n int, rollMax []int) int {
	mod := 1000000007
	dp := [6][15]int{}
	total := [6]int{}
	for i := 0; i < 6; i++ {
		dp[i][0] = 1
		total[i] = 1
	}
	for n > 1 {
		tmp := [6][15]int{}
		for i := 0; i < 6; i++ {
			for j := 0; j < 6; j++ {
				if i != j {
					tmp[i][0] = (tmp[i][0] + total[j]) % mod
				}
			}
			for j := 1; j < rollMax[i]; j++ {
				tmp[i][j] = dp[i][j-1]
			}
		}

		dp = tmp
		for i := 0; i < 6; i++ {
			total[i] = 0
			for j := 0; j < rollMax[i]; j++ {
				total[i] =  (total[i] + dp[i][j]) % mod
			}
		}
		n--
	}
	ret := 0
	for i := 0; i < 6; i++ {
		ret = (ret + total[i]) % mod
	}
	return ret
}
```
