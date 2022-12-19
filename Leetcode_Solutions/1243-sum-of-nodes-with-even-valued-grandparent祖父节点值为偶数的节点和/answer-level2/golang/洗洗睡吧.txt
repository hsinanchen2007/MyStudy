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
var sum int

func sumEvenGrandparent(root *TreeNode) int {
	sum = 0         //清除之前执行代码对 sum (全局变量) 的影响
	todo(root, false, false)
	return sum
}

func todo(root *TreeNode, fa, gra bool) {
	if root == nil {
		return
	}
	if gra {
		sum += root.Val
	}
	todo((*root).Left, root.Val%2 == 0, fa)
	todo(root.Right, root.Val%2 == 0, fa)
}


```