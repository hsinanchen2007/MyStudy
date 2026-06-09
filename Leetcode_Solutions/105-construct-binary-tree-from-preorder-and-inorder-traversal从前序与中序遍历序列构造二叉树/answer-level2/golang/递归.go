依次从前序遍历的数组中取出数据i 去中序遍历的数组中找位置，改位置左边就是i的左子树left，右边即右子树right，然后递归调用前序数组中i+1的左右子树，首先要把i+1在left中找其位置，找不到的话，再在right中找

```

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func buildTree(preorder []int, inorder []int) *TreeNode {
	if len(preorder) == 0 || len(inorder) == 0 {
		return nil
	}

	return buildSubTree(preorder,inorder)
}

func buildSubTree(preorder []int, inorder []int) *TreeNode {
    if len(inorder) == 0 || len(preorder) == 0 {
		return nil
	}
	if len(preorder) == 1 {
		return &TreeNode{Val:preorder[0]}
	}
	head := &TreeNode{Val:preorder[0]}
	i := 0
	for ; i < len(inorder); i++  {
		if inorder[i] == preorder[0] {
			break
		}
	}
    if i>=len(inorder) {
		return nil
	}
	leftSub := inorder[:i]
	rightSub := inorder[i+1:]
	leftNode := buildSubTree(preorder[1:],leftSub)
	if leftNode != nil {
		head.Left = leftNode
		head.Right = buildSubTree(preorder[len(leftSub)+1:],rightSub)
	}else  {
		head.Right = buildSubTree(preorder[1:],rightSub)
	}
	return head
}
```
