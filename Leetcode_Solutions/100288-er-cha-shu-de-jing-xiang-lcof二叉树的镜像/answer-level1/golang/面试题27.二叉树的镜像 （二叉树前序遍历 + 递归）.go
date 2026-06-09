### 解题思路
学习[@wait-for-cheng-shan](/u/wait-for-cheng-shan/)大佬
[大佬文章地址](https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof/solution/er-cha-shu-de-jing-xiang-dui-er-cha-shu-ti-mu-de-l/)

### 知识点：二叉树前序遍历的顺序 + 递归

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
func mirrorTree(root *TreeNode) *TreeNode {
    // 递归函数的终止条件，节点为空时返回
	if root == nil {
		return nil
	}

	// 前序顺序 + 递归
	// 1. 交换当前节点的左右节点
	root.Left, root.Right = root.Right, root.Left
	// 2. 递归当前节点的左子树
	mirrorTree(root.Left)
	// 3. 递归当前节点的右子树
	mirrorTree(root.Right)

	// 函数返回时就表示当前这个节点，以及它的左右子树都交换完了
	return root
}
```