![1.PNG](https://pic.leetcode-cn.com/fe99a6f4b3d8bf6716cef65ddbd2e1f123c12af5af6e0cf8a967dd10cf18966a-1.PNG)

[leetcode-golang](https://github.com/laijinhang/leetcode-golang)
### 解题思路
两种解法：
1、广度优先搜索（bfs、队列实现）
2、深度优先搜索（dfs、栈实现）

下面的实现是dfs
### 代码

```golang
func movingCount(m int, n int, k int) int {
	arr := make([][]bool, m)
	for i := 0;i < m;i++ {
		arr[i] = make([]bool, n)
	}
	return dfs(0, 0, m, n, k, arr)
}

func dfs(i, j, m, n, k int, arr [][]bool) int {
	if i < 0 || i >= m || j < 0 || j >= n || unitsDigitSum(i, j) > k || arr[i][j] {
		return 0
	}
	arr[i][j] = true
	return dfs(i+1, j, m, n, k, arr) + dfs(i, j+1, m, n, k, arr) + dfs(i-1, j, m, n, k, arr) + dfs(i, j-1, m, n, k, arr) + 1
}

func unitsDigitSum(a, b int) int {
	s := 0
	for ;a > 0;a /= 10 {
		s += a % 10
	}
	for ;b > 0;b /= 10 {
		s += b % 10
	}
	return s
}
```