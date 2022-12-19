### 解题思路
此处撰写解题思路

   dp[i][j] 跟 dp[i+1][j-1] ,dp[i][j-1],dp[i+1][j] 有关，最终终止到i>=j
   - 二位数组中，dp[0][0]到dp[sLen-1][sLen-1]的对角线以及左下方的都是0
   - 每次和对角线平行右移更新

### 代码

```golang
/*
   dp[i][j] 跟 dp[i+1][j-1] ,dp[i][j-1],dp[i+1][j] 有关，最终终止到i>=j
   - 二位数组中，dp[0][0]到dp[sLen-1][sLen-1]的对角线以及左下方的都是0
*/
func minInsertions(s string) int {
	sLen := len(s)

	if sLen == 0 {
		return 0
	}

	// return dp(s, 0, sLen-1)

	arr := make([][]int, sLen)
	for i := 0; i < sLen; i++ {
		arr[i] = make([]int, sLen)
	}

	// 对角线右边的斜线
	for c := 1; c < sLen; c++ {
		i := 0 // arr[0][i]
		j := c
		for j < sLen {

			if s[i] == s[j] {
				arr[i][j] = arr[i+1][j-1]
			} else {
				arr[i][j] = min(arr[i+1][j]+1, arr[i][j-1]+1)
			}
			// return min(dp(s, i+1, j)+1, dp(s, i, j-1)+1)

			i++
			j++

		}
	}

	return arr[0][sLen-1]

}

func min(i, j int) int {
	if i < j {
		return i
	}

	return j
}
```