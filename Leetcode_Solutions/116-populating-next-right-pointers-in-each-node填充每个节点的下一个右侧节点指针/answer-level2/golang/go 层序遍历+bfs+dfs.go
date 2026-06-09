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
```
//bfs
func connect(root *Node) *Node {
	if root == nil {
		return root
	}
	pre := root
	for pre.Left != nil {
		tmp := pre
		for tmp != nil {
			tmp.Left.Next = tmp.Right
			if tmp.Next != nil {
				tmp.Right.Next = tmp.Next.Left
			}
			tmp = tmp.Next
		}
		pre = pre.Left
	}
	return root
}
```

```
//dfs
func connect(root *Node) *Node {
	if root == nil {
		return root
	}
	DFSconnect(root)
	return root

}

func DFSconnect(root *Node) {
	if root == nil {
		return
	}
	left := root.Left
	right := root.Right
	for left != nil {
		left.Next = right
		left = left.Right
		right = right.Left
	}
	DFSconnect(root.Left)
	DFSconnect(root.Right)
}
```


