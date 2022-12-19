此题跟斐波那契数列问题非常相似

### 暴力递归，超时
遍历所有情况，而且有重复计算
```go

func minimumTotal(triangle [][]int) int {
	minSum = int(^uint(0) >> 1)

	helper(triangle, 0, 0, 0)
	return minSum
}

func helper(triangle [][]int, sum int, r int, c int) {
	sum += triangle[r][c]
	if r == len(triangle)-1 {
		if sum < minSum {
			minSum = sum
		}
		return
	}

	if r+1 < len(triangle) {
        helper(triangle, sum, r+1, c)
        helper(triangle, sum, r+1, c+1)
	}
}
```

### 动态规划
计算以每一行节点为末尾节点的路径的和的最大值。设节点行数为n
- n==0 ,返回0
- n==1 返回triangle[0][0]
- n==2,返回两个和中的较大值
- 以新一行节点为结尾的路径，除了左右两端节点外，其他节点都有两个流入路径，取较大流入路径和即可。遍历计算后，我们得到所有以最后一行节点为末尾节点的路径的和的最大值
```go

func minimumTotal(triangle [][]int) int {
	if len(triangle) == 0 {
		return 0
	}
	if len(triangle) == 1 {
		return triangle[0][0]
	}
	if len(triangle) == 2 {
		if triangle[1][1] < triangle[1][0] {
			return triangle[0][0] + triangle[1][1]
		}
		return triangle[0][0] + triangle[1][0]
	}

	dp := make([]int, len(triangle))
	dp[0], dp[1] = triangle[0][0]+triangle[1][0], triangle[0][0]+triangle[1][1]

	for r := 2; r < len(triangle); r++ {
		for c := len(triangle[r]) - 1; c >= 0; c-- {
			if 0 < c && c < len(triangle[r])-1 {
				if dp[c]+triangle[r][c] > dp[c-1]+triangle[r][c] {
					dp[c] = dp[c-1] + triangle[r][c]
					continue
				}
				dp[c] = dp[c] + triangle[r][c]
			} else if c == len(triangle[r])-1 {
				dp[c] = dp[c-1] + triangle[r][c]
			} else {
				dp[c] = dp[c] + triangle[r][c]
			}
		}
	}

	sort.Ints(dp)
	return dp[0]
}


```