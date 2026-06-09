### 解题思路
这道题和岛屿那道题不一样，这道题可以看做是 邻接矩阵表示的图

当成邻接矩阵来访问 行表示第i个人，列表示第i个人有联系的人（1表示有朋友关系，0表示没有朋友关系）
即一维的人，用visited来表示，深度优先搜索和这个人有关系的人，并将搜索到的人置为已经访问过


### 代码

```golang
func findCircleNum(M [][]int) int {
	if len(M) == 0 {
		return 0
	}
	res := 0
	// 当成邻接矩阵来访问 行表示第i个人，列表示第i个人有联系的人（1表示有朋友关系，0表示没有朋友关系）
	visited := make([]int, len(M))
	for i := 0; i < len(M); i++ {
		if visited[i] == 0 {
			// 自己算是一个朋友圈
			res++
			DFS(M, visited, i)
		}
	}
	return res
}

func DFS(M [][]int, visited []int, i int) {
	visited[i] = 1
	for j := 0; j < len(M); j++ {
		if visited[j] == 0 && M[i][j] == 1 {
			DFS(M, visited, j)
		}
	}
}

```