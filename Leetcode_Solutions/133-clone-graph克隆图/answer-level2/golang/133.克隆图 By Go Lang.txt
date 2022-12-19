### 解题思路
1. 广度优先BFS
2. 实时更新状态，表示是否访问过
3. 用Map保持mapping关系，key为旧图的Val，value为新图的Node Pointer

### 代码

```golang
func cloneGraph(node *Node) *Node {
	if node == nil {
		return nil
	}
	M := make(map[int]*Node)

	buf := []*Node{node}
	newNode := Node{Val: node.Val, Neighbors: []*Node{}}
	M[node.Val] = &newNode

	for len(buf) > 0 {
		var t []*Node
		for i := 0; i < len(buf); i++ {
			n := buf[i]
			for j := 0; j < len(n.Neighbors); j++ {
				v, ok := M[n.Neighbors[j].Val]
				if !ok {
					newN := Node{Val: n.Neighbors[j].Val, Neighbors: []*Node{}}
					M[n.Neighbors[j].Val] = &newN
					t = append(t, n.Neighbors[j])
					M[n.Val].Neighbors = append(M[n.Val].Neighbors, &newN)
				} else {
					M[n.Val].Neighbors = append(M[n.Val].Neighbors, v)
				}
			}
		}
		buf = t
	}
	return &newNode
}

```