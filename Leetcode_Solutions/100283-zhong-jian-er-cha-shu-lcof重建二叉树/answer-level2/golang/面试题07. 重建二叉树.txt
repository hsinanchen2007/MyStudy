### 解题思路


### 代码

```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
// 重建二叉树
func buildTree(preorder []int, inorder []int) *TreeNode {
    // 1.如果前序遍历和中序遍历有一个为空,则返回
	if len(preorder) == 0 || len(inorder) == 0 {
		return nil
	}
	// 2.如果前序遍历的值和中序遍历的值不一致,则返回
	if len(preorder) != len(inorder) {
		return nil
	}

	// 3.根节点是前序遍历的第一个值
	tree := &TreeNode{}
	tree.Val = preorder[0]
	if len(preorder) == 1 {
		return tree
	}

	left := 0
	right := 0
	// 2.找到中序排列中根节点的位置
	for i := 0; i < len(inorder); i++ {
		if inorder[i] == preorder[0] {
			break
		}
		left++
	}
	// 前序遍历 preorder = [3,9,20,15,7]  根左右
	// 中序遍历 inorder = [9,3,15,20,7]	左根右
	// 举个例子
	// 第一次遍历  left = 1  right = 5- 1 -1 = 3
	right = len(preorder) - left - 1
	if left > 0 {
		tree.Left = buildTree(preorder[1:left+1], inorder[0:left])
	}

	if right > 0 {
		tree.Right = buildTree(preorder[left+1:], inorder[left+1:])
	}
	return tree
}
```