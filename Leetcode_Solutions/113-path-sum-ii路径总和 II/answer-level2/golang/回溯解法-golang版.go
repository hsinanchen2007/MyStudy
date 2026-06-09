```
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func pathSum(root *TreeNode, sum int) [][]int {
    res := make([][]int, 0)
    helper(root, sum, []int{}, &res)
    return res
}

func helper(root *TreeNode, remain int, node []int, res *[][]int) {
    switch {
    case root==nil:

    case root.Left == nil && root.Right == nil:
        if remain == root.Val {
            tmp := make([]int, len(node))
            copy(tmp, node)
            *res = append(*res, append(tmp, root.Val))
        }

    default:
        if root.Left != nil {
            node = append(node, root.Val)
            helper(root.Left, remain-root.Val, node, res)
            node = node[:len(node)-1]
        }

        if root.Right != nil {
            node = append(node, root.Val)
            helper(root.Right, remain-root.Val, node, res)
            node = node[:len(node)-1]
        }
    }
}
```