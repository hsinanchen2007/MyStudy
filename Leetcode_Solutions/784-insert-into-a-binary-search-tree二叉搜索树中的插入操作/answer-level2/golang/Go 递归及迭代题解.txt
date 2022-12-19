1. 递归解法

```Go []
func insertIntoBSTV1(root *TreeNode, val int) *TreeNode {
	if root == nil {
		return nil
	}
	if root.Val > val {
		if root.Left != nil {
			insertIntoBST(root.Left, val)
		} else {
			root.Left = &TreeNode{val, nil, nil}
		}
	} else {
		if root.Right != nil {
			insertIntoBST(root.Right, val)
		} else {
			root.Right = &TreeNode{val, nil, nil}
		}
	}
	return root
}
```

2. 迭代解法

```Go []
func insertIntoBST(root *TreeNode, val int) *TreeNode {
	if root == nil {
		return nil
	}
	r := root
	for {
		if r.Val > val {
			if r.Left == nil {
				r.Left = &TreeNode{val, nil, nil}
				break
			} else {
				r = r.Left
			}
		} else {
			if r.Right == nil {
				r.Right = &TreeNode{val, nil, nil}
				break
			} else {
				r = r.Right
			}
		}
	}
	return root
}
```

[LeetCodeByGo: 更多LeetCode题库Go语言题解](https://github.com/mrandmrsbenben/LeetCodeByGo)