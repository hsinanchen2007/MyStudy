### 解题思路
递归，

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
 var max int = 0
func diameterOfBinaryTree(root *TreeNode) int {
    max=0
    GetHeight(root)
    return max
}

func GetHeight(root *TreeNode) int{
    if root==nil {
		return 0
	}
	left := GetHeight(root.Left)
	right := GetHeight(root.Right)
	if left+right>max{
		max=left+right
	}
	if left>right{
		return left+1
	}else {
		return right+1
	}
}
```