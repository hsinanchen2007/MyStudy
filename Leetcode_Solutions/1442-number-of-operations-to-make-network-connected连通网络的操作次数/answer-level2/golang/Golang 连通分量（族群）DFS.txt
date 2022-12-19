### 性能

* 执行用时 :88 ms, 在所有 Go 提交中击败了64.86%的用户
* 内存消耗 : 14.6 MB, 在所有 Go 提交中击败了100.00%的用户

### 解题思路

图论里面有个定理：为了链接n个节点，必须有n-1条边。

如果我们把联通分量（子网）看成node，题目就变成了需要几条边才能链接这些子网。

* 首先我们检查当前已有的边的数量和节点数量的关系，如果不满足定理返回-1。
* 接下来构建一个2D表来记录节点`i`的直接邻居。
* 一个`n`长度的数组来记录某个节点`i`是否被在DFS探索族群的时候被访问过，如果被访问过，说明这个节点属于某个子网。如果没有被访问过，说明这个节点属于一个新子网，我们从这个节点开始DFS去构建他的子网，此时子网数+1。
* 最后返回集子网数 -1 就是需要的最少边联通这些子网。




### 代码

```golang
// Thorem: for n points, we need at least n-1 lines to
// connected n.
//
func makeConnected(n int, connections [][]int) int {

	if len(connections) < n-1 {
		return -1
	}

	// Create a graph by 2D table.
	// g[i] is the neighbors of i.
	// O(E)
	g := make([][]int, n)
	for i := range g {
		g[i] = make([]int, 0)
	}

	for _, c := range connections {
		g[c[0]] = append(g[c[0]], c[1])
		g[c[1]] = append(g[c[1]], c[0])
	}

	// Records the seen nodes.
	// Every node need only be visited once!
	seen := make([]int, n)
	// The current connected custers' count.
	count := 0

	for i := 0; i < n; i++ {
		// If node i has been visited,
		// means i is not a new node needed to be connected.
		if seen[i] != 0 {
			continue
		} else {
			count++
			// Mark all node i's connected node.
			dfs(i, g, seen)
		}
	}
	return count - 1
}

// deep first search to mark all can reached node from cur node.
// From the current node, to check its neighbors,
func dfs(cur int, g [][]int, seen []int) {

	for _, nxt := range g[cur] {
		// If its' neighbor has not been visited.
		if seen[nxt] == 0 {
			// Mark its neighbor to been visited.
			seen[nxt]++
			// Then deep search the neighbor.
			dfs(nxt, g, seen)
		}
	}
}

```