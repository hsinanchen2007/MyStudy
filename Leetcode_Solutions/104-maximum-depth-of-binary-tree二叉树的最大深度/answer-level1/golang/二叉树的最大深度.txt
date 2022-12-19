### 解题思路
显然这是一个递归问题。

求二叉树的最大深度，根节点的最大深度就是子节点的最大深度加一；
那么问题就转换为求左子节点的最大深度加一、右子节点的最大深度加一；
然后比较左子节点和右子节点那个深度大即可。

 
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

    leftMax := maxDepth(root.Left) + 1
    rightMax := maxDepth(root.Right) + 1
    if leftMax >= rightMax {
        return leftMax
    } else {
        return rightMax
    }

}
```