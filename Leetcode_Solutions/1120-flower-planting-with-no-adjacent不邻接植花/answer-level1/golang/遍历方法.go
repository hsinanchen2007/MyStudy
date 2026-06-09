逐个花圃进行遍历，使用的是邻接表，用邻接矩阵遇到稀疏矩阵会超时！
方法比较笨，下一步考虑用BFS优化

```
type Node struct {
	val int
	next []int
}

func gardenNoAdj(N int, paths [][]int) []int {
	var adj = make([]Node, N)
	for i := 0; i < N; i++ {
		adj[i] = Node{}
		adj[i].val = i
		adj[i].next = []int{}
	}
	for i := 0; i < len(paths); i++ {
		row, col := paths[i][0], paths[i][1]
		adj[row-1].next = append(adj[row-1].next, col-1)
		adj[col-1].next = append(adj[col-1].next, row-1)
	}
	
	res := make([]int, N)

	for i := 0; i < N; i++ {
		// 未访问
		if res[i] == 0 {
			mmap := make(map[int]int)  // 花：花圃
			for j := 0; j < len(adj[i].next); j++ {
				index := adj[i].next[j]
				if res[index] != 0 {
					mmap[res[index]] = index
				}
			}
			for f := 1; f <= 4; f++ {
				if _, ok := mmap[f]; !ok{
					res[i] = f // f花未被种
				}
			}
		}

	}
	return res
}
```