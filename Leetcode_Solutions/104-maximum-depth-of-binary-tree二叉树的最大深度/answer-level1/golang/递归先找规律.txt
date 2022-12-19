### 解题思路
根节点的最大深度等于左右子树深度最大值+1

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
    if root==nil{
        return 0
    }
    return 1+int(math.Max(float64(maxDepth(root.Left)),float64(maxDepth(root.Right))))
}
```