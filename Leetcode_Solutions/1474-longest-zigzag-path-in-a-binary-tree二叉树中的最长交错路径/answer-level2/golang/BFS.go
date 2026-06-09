```
type obj struct {
	node  *TreeNode
	left  int
	right int
}

func longestZigZag(root *TreeNode) int {
	var (
		rst  int
		curr obj
		l    = list.New()
	)
	if root == nil {
		return 0
	}
	l.PushBack(obj{
		node:  root,
		left:  0,
		right: 0,
	})

	for l.Len() != 0 {
		curr = l.Remove(l.Front()).(obj)
		if curr.node.Left != nil {
			l.PushBack(obj{
				node:  curr.node.Left,
				left:  curr.right + 1,
				right: 0,
			})
		} else {
			if curr.right > rst {
				rst = curr.right
			}
		}
		if curr.node.Right != nil {
			l.PushBack(obj{
				node:  curr.node.Right,
				left:  0,
				right: curr.left + 1,
			})
		} else {
			if curr.left > rst {
				rst = curr.left
			}
		}
	}
	return rst
}
```
