### 解题思路
递归计数即可

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
func countNodes(root *TreeNode) int {
    if root == nil {
        return 0
    }
    
    count := 0
    count++ // 根节点
    count += countNodes(root.Left) // 左子树
    count += countNodes(root.Right) // 右子树
    return count
}
```