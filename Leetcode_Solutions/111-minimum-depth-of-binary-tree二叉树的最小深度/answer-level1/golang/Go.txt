### 解题思路
此处撰写解题思路

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
var min int 

func minDepth(root *TreeNode) int {
    if root == nil{
        return 0
    }
    deep := 0
	min = 100000
	process(root , deep)
	return min
}


func process(root *TreeNode, deep int) {
	if root != nil {
		deep++
		process(root.Left, deep)
		process(root.Right, deep)
        if root.Left == nil && root.Right == nil {
            if deep < min{
                min = deep
            }
        }
	}
}

```