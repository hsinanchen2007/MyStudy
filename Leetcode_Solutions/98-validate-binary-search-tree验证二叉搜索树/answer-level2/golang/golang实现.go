1. BST的中序遍历是升序序列
```golang
func isValidBST(root *TreeNode) bool {
	val := -1 << (8*unsafe.Sizeof(1) - 1)
	cur := root
	for cur != nil {
		if cur.Left == nil {
			if cur.Val > val {
				val = cur.Val
			} else {
				return false
			}
			cur = cur.Right
		} else {
			prev := cur.Left
			for prev.Right != nil && prev.Right != cur {
				prev = prev.Right
			}

			if prev.Right == nil {
				prev.Right = cur
				cur = cur.Left
			} else {
				if cur.Val > val {
					val = cur.Val
				} else {
					return false
				}
				prev.Right = nil
				cur = cur.Right
			}
		}
	}
	return true
}
```

2. 直接根据BST的定义递归判断
```golang
func isValidBST(root *TreeNode) bool {
	min := -1 << (8*unsafe.Sizeof(1) - 1)
	max := 1<<(8*unsafe.Sizeof(1)-1) - 1
	return _isValidBST(root, min, max)
}

func _isValidBST(root *TreeNode, min, max int) bool {
	if root == nil {
		return true
	}
	v := root.Val
	if root.Right != nil {
		if r := root.Right.Val; r <= min || r >= max || r <= v {
			return false
		}

	}
	if root.Left != nil {
		if l := root.Left.Val; l >= max || l <= min || l >= v {
			return false
		}
	}

	return _isValidBST(root.Right, v, max) && _isValidBST(root.Left, min, v)
}

```