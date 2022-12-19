```
func connect(root *Node) *Node {
	if root == nil {
		return root
	}
	nodes := make([]*Node, 0)
	nodes = append(nodes, root)
	for len(nodes) != 0 {
		size := len(nodes)
		for i := 0; i < size; i++ {

			node := nodes[0]
			nodes = nodes[1:]
			if i < size-1 {
				node.Next = nodes[0]
			}
			if node.Left != nil {
				nodes = append(nodes, node.Left)
			}
			if node.Right != nil {
				nodes = append(nodes, node.Right)
			}
		}
	}
	return root
}
```
