### 解题思路

动态规划：编辑代价来自三个部分，插入、删除和替换
- 首先声明并dp数组，`dp[m+1][n+1]`
	- 初始化特殊情况，即第一列和第一行
	- 第一列即为`dp[0][i]`，将空串编辑为`word2[:i]`的代价，即插入字符的代价
	- 第一行为 `dp[i][0]`表示将`word1[:i]`编辑为空串的代价
- 然后进入一般情况
	- 当`word1[i-1] == word2[j-1]`，此时说明当前不需要编辑，`dp[i][j] = dp[i-1][j-1]`，否则增加替换次数，编辑代价+1，即`dp[i][j] = dp[i-1][j-1] + 1`
	- 接下来还需要判断当插入或者删除时所需要的编辑代价最小。
	-  dp[i][j] = min(dp[i][j], dp[i][j-1] + 1) 表示插入
	- dp[i][j] = min(dp[i][j], dp[i-1][j] + 1) 表示删除

### 代码

```golang
func minDistance(word1 string, word2 string) int {
	m, n := len(word1), len(word2)
	var dp = make([][]int, m+1)
	for i := 0; i <= m; i++ {
		dp[i] = make([]int, n+1)
	}
	// 空字符串编辑为空字符串的编辑代价为0
	dp[0][0] = 0
	// dp[i][0]表示编辑为空串的代价，即为将所有字符删除的代价
	for i := 1; i <= m; i++ {
		dp[i][0] = i 
	}
	// dp[0][i]表示将空串编辑为str2[:i]的代价，即插入字符的代价
	for i := 1; i <= n; i++ {
		dp[0][i] = i
	}
	// 下面是动态规划的主方法
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			if word1[i-1] == word2[j-1] {
				dp[i][j] = dp[i-1][j-1]              // 如果 word1[i-1] 与 word2[i-1]相等
			} else {
				dp[i][j] = dp[i-1][j-1] + 1          // 替换代价
			}
			dp[i][j] = min(dp[i][j], dp[i][j-1] + 1) // 插入代价
			dp[i][j] = min(dp[i][j], dp[i-1][j] + 1) // 删除代价
		}
	}
	return dp[m][n]
}

func min(a, b int) int {
	if a > b {
		return b 
	}
	return a
}
```