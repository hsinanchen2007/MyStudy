### bfs
[对应模板 Github](https://github.com/temporaries/leetcode/blob/master/templates/tree/bfs.go)

```golang
func connect(root *Node) *Node {
	if root == nil {
		return nil
	}
	pre := root

	for pre.Left != nil {
		parent := pre
		for parent != nil {
			parent.Left.Next = parent.Right //左节点连接右节点
			if parent.Next != nil {
				parent.Right.Next = parent.Next.Left //右节点 连接 邻居左节点
			}
			parent = parent.Next //同层移动
		}
		pre = pre.Left //移到下层
	}
	return root
}
```

### dfs
因为根节点先处理，勉强当作 `前序遍历`
[对应模板 Github](https://github.com/temporaries/leetcode/blob/master/templates/tree/preorder.go)

1. 左节点不断往右，右节点不断往左，像拉链一样拉紧！

```golang
func connect(root *Node) *Node {
	if root == nil {
		return nil
	}
	l := root.Left
	r := root.Right
	for l != nil {
		l.Next = r //连接
		l = l.Right //往右
		r = r.Left //往左
	}
	connect(root.Left)
	connect(root.Right)
	return root
}
```

[Go版本 Github](https://github.com/temporaries/leetcode)
