### Go
![177cd3d5dde1cf1e2a5a13f7c7ecef6.png](https://pic.leetcode-cn.com/c8d5fa999a9c322640cd47ae39501dbf69755ef0231f4afe41b1bd1a8d589a4f-177cd3d5dde1cf1e2a5a13f7c7ecef6.png)

### Python
![8dd11d42d8ef782e733027f433ab844.png](https://pic.leetcode-cn.com/ba8e5bb039d63330c1439e69713abfc8ccc942cbac32dabd9541e2d461264b7c-8dd11d42d8ef782e733027f433ab844.png)
### 注意点
1. 在进入DFS前，设置`temp`变量记录`board[i][j]`原来的值，然后把`board[i][j]`的值原地改为`' '`
2. 等从DFS出来后，再把`board[i][j]`改回原来的值
3. 这样就可以避免重复进入
4. 因为是原地修改，避免了辅助变量，开销较小


### 代码
```go []
func exist(board [][]byte, word string) bool {
	m, n := len(board), len(board[0])
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if dfs(board, i, j, word, 0) {
				return true
			}
		}
	}
	return false
}

func dfs(board [][]byte, i int, j int, word string, k int) bool {
	if board[i][j] != word[k] {
		return false
	}
	if k == len(word)-1 {
		return true
	}
	temp := board[i][j]
	board[i][j] = byte(' ')
	if 0 <= i-1 && dfs(board, i-1, j, word, k+1) {
		return true
	}
	if i+1 < len(board) && dfs(board, i+1, j, word, k+1) {
		return true
	}
	if 0 <= j-1 && dfs(board, i, j-1, word, k+1) {
		return true
	}
	if j+1 < len(board[0]) && dfs(board, i, j+1, word, k+1) {
		return true
	}
	board[i][j] = temp
	return false
}
```
```python []
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        def dfs(i, j, k):
            if board[i][j] != word[k]:
                return False
            if k == len(word) - 1:
                return True
            board[i][j] += ' '
            for p, q in zip((i-1, i+1, i, i), (j, j, j-1, j+1)):
                if 0 <= p < m and 0 <= q < n:
                    if dfs(p, q, k+1):
                        return True
            board[i][j] = board[i][j][0]
            return False

        m, n = len(board), len(board[0])
        for i in range(m):
            for j in range(n):
                if dfs(i, j, 0):
                    return True
        return False
                
        
```

