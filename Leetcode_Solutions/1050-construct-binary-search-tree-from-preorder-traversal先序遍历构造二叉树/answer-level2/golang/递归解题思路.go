```
func bstFromPreorder(preorder []int) *TreeNode {
	if len(preorder) < 1 {
		return nil
	}
	// 确立根节点
	root := &TreeNode{
		Val: preorder[0],
	}

	// 先序遍历依次是根结点、左子树、右子树
	// 且所有左子树的值小于根节点
	// 所有右子树的值大于根节点
	// 据此遍历获取右子树的根节点索引
	right := 0
	for ; right < len(preorder); right++ {
		if preorder[right] > root.Val {
			break
		}
	}

    // 所以左子树的值索引为 1-left
	left := right - 1
	if left > 0 {
		root.Left = bstFromPreorder(preorder[1 : left+1])
	}
	if right > 0 {
		root.Right = bstFromPreorder(preorder[right:])
	}

	return root
}
```
