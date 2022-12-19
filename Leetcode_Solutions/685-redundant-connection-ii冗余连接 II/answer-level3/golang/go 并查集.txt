
**两种情况**
    1. 存在入度为2 的节点, 去掉一条边, 用并查集判断剩余边是否存在环。
    2. 并查集找出最后一条导致环路的边。
<br />

**执行结果**
![image.png](https://pic.leetcode-cn.com/c7f80a69aea6037abd82c85d75bbf45c35b55c95a58771909e05b7420b7a7850-image.png)
<br />

**代码**
```
type UnionFind struct {
	Parent []int
	Height []int
}

func (uf *UnionFind) Find(x int) int {
	for x != uf.Parent[x] {
		x = uf.Parent[x]
	}
	return x
}

func (uf *UnionFind) Union(x, y int) bool {

	xParent := uf.Find(x)
	yParent := uf.Find(y)

	if xParent == yParent {
		return false
	}

	if uf.Height[xParent] > uf.Height[yParent] {
		uf.Parent[yParent] = uf.Parent[xParent]
	} else if uf.Height[xParent] < uf.Height[yParent] {
		uf.Parent[xParent] = uf.Parent[yParent]
	} else {
		uf.Parent[xParent] = uf.Parent[yParent]
		uf.Height[yParent]++
	}

	return true
}

func getUF(size int) *UnionFind {
	uf :=  &UnionFind{
		Parent: make([]int, size, size),
		Height: make([]int, size, size),
	}

	for i := 0; i < size; i++ {
		uf.Parent[i] = i
	}

	return uf
}

func findRedundantDirectedConnection(edges [][]int) []int {

	l := len(edges)
	inDegree := make([]int, l + 1, l + 1)

	for index, edge := range edges {

		if inDegree[edge[1]] != 0 {	//存在入度为2的节点

			//去掉一条边, 判断是否有环路
			edges = append(edges[:index], edges[index+1:]...)
			if _, isCycle := IsCycle(edges, l + 1); isCycle {
				return edges[inDegree[edge[1]] - 1]
			} else {
				return edge
			}
		}

		inDegree[edge[1]] = index + 1
	}

	edge, _ := IsCycle(edges, l + 1)
	return edge
}

/*
	检查环路
*/
func IsCycle(edges [][]int, size int) ([]int, bool) {

	uf := getUF(size)

	for _, edge := range edges {
		if !uf.Union(edge[0], edge[1]) {
			return edge, true
		}
	}

	return make([]int, 0, 0), false
}

```

