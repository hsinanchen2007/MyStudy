
通过一个 slice 记录中间路径结果

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
    rs := make([][]int, 0)
    if root == nil {
        return rs
    }
    
    r := make([]int, 0)
    pathSumRecur(root, sum, &rs, r)
    return rs
}

func pathSumRecur(root *TreeNode, sum int, rs *[][]int, r []int) {
    if root == nil {
        return 
    }
    
    sum = sum - root.Val 
    r = append(r, root.Val)
    
    if root.Left == nil && root.Right == nil {
        if sum == 0 {
            n := make([]int, len(r))
            copy(n, r)
            *rs = append(*rs, n)
        }
    }
    
    if root.Left != nil {
        pathSumRecur(root.Left, sum, rs, r)
    }
    if root.Right != nil {
        pathSumRecur(root.Right, sum, rs, r)
    }
    
}
```