```
// 对每个人执行BFS，如果已经执行过BFS，则跳过
// 朋友圈的数量就是BFS的次数
func findCircleNum(M [][]int) int {    
	n := len(M)
	count := 0	
	// 记录n个人是否都执行过bfs
	visited := make([]int, n)
    var queue []int

	for i := 0; i < n; i++ {        
		if visited[i] == 0 {
			// 从第i个人开始BFS搜朋友
			queue = append(queue, i)
			for len(queue) > 0 {
                // 搜索到第s个人
				s := queue[0]
				queue = queue[1:]
				visited[s] = 1
				for j := 0; j < n; j++ {
					// 找第s个人的朋友
					if M[s][j] == 1 && visited[j] == 0 {
						queue = append(queue, j)
					}
				}
			}
			count++
		}
	}
	return count
}

```
