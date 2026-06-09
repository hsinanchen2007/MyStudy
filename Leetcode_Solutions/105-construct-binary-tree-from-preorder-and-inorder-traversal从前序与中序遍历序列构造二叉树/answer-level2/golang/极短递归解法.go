### 解题思路
思路就是如果前序中某一元素的值与中序的某一元素值相同时，该值就是左右子树的划分点，最大的关注点在于左右子树中的节点的数量，向下递归子树的时候前序和中序数组的划分注意下就可以了，自认为代码足够短，也很好理解

### 代码

```golang
func build(preorder []int, inorder []int) *TreeNode {
	if len(preorder) == 0 {
		return nil
	}
	root := &TreeNode{Val: preorder[0]}
	if len(inorder) == 1 {
		return root
	}
	for i:=0; i < len(inorder); i++ {
		if inorder[i] == preorder[0] {
			root.Left = build(preorder[1:1+len(inorder[:i])], inorder[:i])
			root.Right = build(preorder[1+len(inorder[:i]):], inorder[i+1:])
		}
	}
	return root
}

func buildTree(preorder []int, inorder []int) *TreeNode {
	if len(preorder) == 0 {
		return nil
	}
	return build(preorder, inorder)
}

```