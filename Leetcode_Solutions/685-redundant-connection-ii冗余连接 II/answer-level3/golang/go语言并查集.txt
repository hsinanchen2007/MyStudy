如果存在入度为2的节点，优先删除后出现的边，如果不存在入度为2的节点，那一定是根节点的入度为1，此时可以当做无向图处理，删除一条边使之不存在环即可
```
func findRedundantDirectedConnection(edges [][]int) []int {
	indegree := make([]int, len(edges)+1)
	for i, val := range edges {
		indegree[val[1]]++
		if indegree[val[1]] == 2 {
			var first int
			for j, v := range edges {
				if v[1] == val[1] {
					first = j
					break
				}
			}
			return deletedge2(edges, first, i)
		}
	}
	return deletedge1(edges)
}
func deletedge2(edges [][]int, a int, b int) []int {
	copyslice := make([][]int, len(edges))
	copy(copyslice, edges)
	if isring(append(copyslice[:b],copyslice[b+1:]...)) == false {
		return edges[b]
	} else {
		return edges[a]
	}
}
func isring(edges [][]int) bool {
	p := make([]int, len(edges)+2)
	//var res []int
	for i := 1; i <= len(edges); i++ {
		p[i] = i
	}
	for _, val := range edges {
		x := find(val[0], p)
		y := find(val[1], p)
		if x == y {
			return true
		}
		union(x, y, p)
	}
	return false
}
func deletedge1(edges [][]int) []int {
	p := make([]int, len(edges)+1)
	var res []int
	for i := 1; i <= len(edges); i++ {
		p[i] = i
	}
	for _, val := range edges {
		x := find(val[0], p)
		y := find(val[1], p)
		if x != y {
			union(x, y, p)
		} else {
			res = val
		}
	}
	return res
}
func find(x int, p []int) int {
	if p[x] != x {
		p[x] = find(p[x], p)
	}
	return p[x]
}
func union(x int, y int, p []int) {
	xroot := find(x, p)
	yroot := find(y, p)
	if xroot != yroot {
		p[xroot] = yroot
	}
}
```
