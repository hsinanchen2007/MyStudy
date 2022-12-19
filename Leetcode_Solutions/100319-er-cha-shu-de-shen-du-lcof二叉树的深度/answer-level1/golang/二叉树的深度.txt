### 解题思路
递归计算左右子树深度，取较大的即可
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
func maxDepth(root *TreeNode) int {
    if root == nil {
        return 0
    }
    ld := maxDepth(root.Left) + 1
    rd := maxDepth(root.Right) + 1
    if ld > rd {
        return ld
    }
    return rd
}
```