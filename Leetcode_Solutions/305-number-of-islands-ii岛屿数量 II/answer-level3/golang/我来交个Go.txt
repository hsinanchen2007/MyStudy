### 解题思路
此处撰写解题思路

### 代码

```golang
type Node struct {
	X int
	Y int
}

func numIslands2(m int, n int, positions [][]int) []int {
	result := make([]int, 0, 4)
	f := make(map[Node]Node)
	rootMap := make(map[Node]bool)

	for _, pos := range positions {
		node := Node{pos[0], pos[1]}
		f[node] = node
		rootMap[node] = true

		node1 := Node{node.X+1, node.Y}
		node2 := Node{node.X-1, node.Y}
		node3 := Node{node.X, node.Y+1}
		node4 := Node{node.X, node.Y-1}

		if _, ok := f[node1]; ok {
			par := searchParent(node1, f)
			f[par] = node
			if par != node {
				delete(rootMap, par)
			}
		}
		if _, ok := f[node2]; ok {
			par := searchParent(node2, f)
			f[par] = node
			if par != node {
				delete(rootMap, par)
			}
		}
		if _, ok := f[node3]; ok {
			par := searchParent(node3, f)
			f[par] = node
			if par != node {
				delete(rootMap, par)
			}
		}
		if _, ok := f[node4]; ok {
			par := searchParent(node4, f)
			f[par] = node
			if par != node {
				delete(rootMap, par)
			}
		}
		
		result = append(result, len(rootMap))
	}

	return result
}

func searchParent(root Node, f map[Node]Node) Node {
	r := root
	for f[root] != root {
		root = f[root]
	}

	for f[r] != root {
		j := f[r]
		f[r] = root
		r = j
	}

	return root
}

func abs(a int) int {
	if a > 0 {
		return a
	} else {
		return -a
	}
}
```