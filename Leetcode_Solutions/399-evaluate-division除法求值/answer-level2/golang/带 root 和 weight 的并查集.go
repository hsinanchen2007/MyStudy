相对于包含 find 函数的并查集，这里把复杂度放到了 unite 中，使得插入的复杂度为 O（N），但是查询复杂度为 O（1）


```
type usNode struct {
	parent *usNode
	root   *usNode
	rank   int
	val    string
	weight float64
}

func calcEquation(equations [][]string, values []float64, queries [][]string) (rst []float64) {
	var (
		i      int
		exists bool
		// node 编号
		nodes = map[string]*usNode{}
		// node 相对于 root 的比值
		equationMap = map[string]map[string]float64{}
		query       []string
		length      = len(equations)
	)

	for i = 0; i < length; i++ {
		query = equations[i]
		if _, exists = nodes[query[0]]; !exists {
			nodes[query[0]] = &usNode{val: query[0], parent: nil, root: nil, rank: 0, weight: 1.0}
			nodes[query[0]].root = nodes[query[0]]
			nodes[query[0]].parent = nodes[query[0]]
		}
		if _, exists = nodes[query[1]]; !exists {
			nodes[query[1]] = &usNode{val: query[1], parent: nil, root: nil, rank: 0, weight: 1.0}
			nodes[query[1]].root = nodes[query[1]]
			nodes[query[1]].parent = nodes[query[1]]
		}
		if _, exists = equationMap[query[0]]; !exists {
			equationMap[query[0]] = map[string]float64{}
		}
		equationMap[query[0]][query[1]] = values[i]
	}

	for i = 0; i < length; i++ {
		query = equations[i]
		unite(query, nodes, equationMap)
	}

	rst = make([]float64, len(queries))
	for i = 0; i < len(queries); i++ {
		query = queries[i]
		if nodes[query[0]] == nil || nodes[query[1]] == nil ||
			nodes[query[0]].root != nodes[query[1]].root {
			rst[i] = -1
		} else {
			rst[i] = nodes[query[0]].weight / nodes[query[1]].weight
		}
	}
	return
}

func unite(query []string, nodes map[string]*usNode, eqMap map[string]map[string]float64) {
	x := query[0]
	y := query[1]
	if nodes[x].root != nil && nodes[x].root == nodes[y].root {
		return
	}
	if nodes[x].root.rank < nodes[y].root.rank {
		ratio := eqMap[x][y] / nodes[x].weight * nodes[y].weight
		oldRoot := nodes[x].root
		for _, v := range nodes {
			if v.root == oldRoot {
				v.weight *= ratio
				v.root = nodes[y].root
			}
		}
		oldRoot.parent = nodes[y].root
	} else {
		ratio := nodes[x].weight / nodes[y].weight / eqMap[x][y]
		if nodes[x].root.rank == nodes[y].root.rank {
			nodes[x].root.rank++
		}

		// 问题点 如果 node 是 root，那么 root 的子节点不好处理
		oldRoot := nodes[y].root
		for _, v := range nodes {
			if v.root == oldRoot {
				v.weight *= ratio
				v.root = nodes[x].root
			}
		}
		oldRoot.parent = nodes[x].root
	}
}
```
