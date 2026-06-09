### 解题思路
二叉树性质
1.中序遍历是有序的(left,root,right)
2.左子树节点均小于根节点
3.右子树节点均大于根节点
notice 所以先遍历右子树是倒叙 否则是正序

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

func kthLargest(root *TreeNode, k int) int {
	res := make([]int, 0)
	find(root, &res)
	return res[k-1]
}

func find(root *TreeNode, res *[]int) {
	if root.Right != nil {
		find(root.Right, res)
	}
	
	if root != nil {
		*res = append(*res, root.Val)
	}
	if root.Left != nil {
		find(root.Left, res)
	}
	
}
```