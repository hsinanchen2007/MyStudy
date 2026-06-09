### 解题思路
此处撰写解题思路
go 先序递归反转 
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
func invertTree(root *TreeNode) *TreeNode {
    invert(root)
    return root
}

func invert(root *TreeNode) {
    if(root == nil) {
        return 
    }
    root.Left, root.Right = root.Right, root.Left
    invertTree(root.Left)
    invertTree(root.Right)
}
```