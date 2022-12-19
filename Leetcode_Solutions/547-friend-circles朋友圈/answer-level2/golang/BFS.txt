
```
// BFS
func findCircleNum(M [][]int) int {
    if len(M) <= 1 {
        return len(M)
    }
    
    count := 0
    visited := make([]bool, len(M))
    
    for i, _ := range M {
        if visited[i] == false {
            bfs(M, visited, i) // 遍历一次则将一个环全部标记为true，图中BFS防止重复加入，则需要在添加入队列时即设置为true
            count++
        }
    }
    
    return count
}
func bfs(data [][]int, visited []bool, root int) {
	queue := []int{}
	queue = append(queue, root)
	visited[root] = true
	for len(queue) > 0 {
		root = queue[0]
		// visited[i] = true
		queue = queue[1:]
		for i := 0; i < len(data); i++ {
			if data[root][i] == 1 && visited[i] == false {
				visited[i] = true // 放在此处可避免内部有环时被重复入队列，队列中即为访问过的节点，时间更快
				queue = append(queue, i)
			}
		}
	}
}
```