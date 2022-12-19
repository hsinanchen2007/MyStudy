```go

func buildTree(preorder []int, inorder []int) *TreeNode {

	if preorder == nil || len(preorder) == 0 {
		return nil
	}
	var root = &TreeNode{preorder[0], nil, nil}

	if len(preorder) == 1 || len(inorder) == 1 {
		return root
	}

	curInOrderLength := getCurRootIndexInInOrder(preorder, inorder)
	root.Left = buildTree(preorder[1:curInOrderLength+1], inorder[:curInOrderLength])
	root.Right = buildTree(preorder[1+curInOrderLength:], inorder[curInOrderLength+1:])

	return root
}

//返回中序遍历的左右子树长度
func getCurRootIndexInInOrder(preorder []int, inorder []int) int {
	for index, value := range inorder {
		if value == preorder[0] {
			return index
		}
	}

	return -1
}

```
另外有一个case 很奇怪，预期结果应该是前序输出的吧

![屏幕快照 2020-01-12 下午11.56.13.png](https://pic.leetcode-cn.com/3faf5346aa78015fe6e98bdaaabf7e6c56c82dc663db2e4549ef65e40dd4deb3-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-01-12%20%E4%B8%8B%E5%8D%8811.56.13.png)
