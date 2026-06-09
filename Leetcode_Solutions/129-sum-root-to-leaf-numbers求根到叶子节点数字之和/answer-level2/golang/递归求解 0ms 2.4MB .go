### 解题思路

万能递归

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

func sumNumbers(root *TreeNode) int {

	curSum := 0
	sum := 0
	help(root, curSum, &sum)
	return sum
}

func help(root *TreeNode, curNum int, sum *int) {

	if root == nil {
		*sum = curNum + 0
		return
	}

	curNum = curNum*10 + root.Val
	if root.Left == nil && root.Right == nil {
		*sum = *sum + curNum
		return
	}

	if root.Left != nil {
		help(root.Left, curNum, sum)
	}

	if root.Right != nil {
		help(root.Right, curNum, sum)
	}

}

```