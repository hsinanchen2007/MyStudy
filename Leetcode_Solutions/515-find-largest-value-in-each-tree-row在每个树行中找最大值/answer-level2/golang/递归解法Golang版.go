```
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func largestValues(root *TreeNode) []int {
    var res = make([]int, 0)
    helper(root, &res, 0)
    return res
}

func helper(root *TreeNode, res *[]int, depth int) {
    if root == nil {
        return
    }

    if len(*res) == depth {
        *res = append(*res, root.Val)
    }

    if root.Val > (*res)[depth] {
        (*res)[depth] = root.Val
    }

    helper(root.Left, res, depth+1)
    helper(root.Right, res, depth+1)
}
```