```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 * 递归问题思考方法:
 *   1. 对于最简单的情况如何直接定义返回值?
 *   2. 子问题是什么?
 *   3. 假设子问题已经解决,如何通过子问题的解构建当前问题的解?
 */
func hasPathSum(root *TreeNode, sum int) bool {
    if root == nil{
        return false
    }
    if root.Left == nil && root.Right == nil{
        return root.Val == sum
    }
    return hasPathSum(root.Left,sum-root.Val) || hasPathSum(root.Right,sum-root.Val)
}
```