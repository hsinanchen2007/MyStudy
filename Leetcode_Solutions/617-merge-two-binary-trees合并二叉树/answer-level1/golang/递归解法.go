/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func mergeTrees(t1 *TreeNode, t2 *TreeNode) *TreeNode {
    if t2 == nil && t1 == nil {
        return nil
    }
    if t1 == nil {
        return t2
    }
    if t2 == nil {
        return t1
    }

    left := mergeTrees(t1.Left, t2.Left)
    right := mergeTrees(t1.Right, t2.Right)
    t3 := &TreeNode{Val: t1.Val+t2.Val, Left: left, Right: right}
    return t3
}