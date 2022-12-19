```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func levelOrder(root *TreeNode) [][]int {
    res := make([][]int, 0)
    if root == nil {
        return res
    }
    q := []*TreeNode{root}
    for len(q) > 0 {
        n := len(q)
        l := make([]int, 0, n)
        for n > 0 {
            h := q[0]
            q = q[1:]
            n--
            l = append(l, h.Val)
            if h.Left != nil {
                q = append(q, h.Left)
            }
            if h.Right != nil {
                q = append(q, h.Right)
            }
        }
        res = append(res, l)
    }
    return res
}
```