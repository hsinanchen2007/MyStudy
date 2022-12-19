这个的问题是递归有点难理解
首先定义:  左节点所有节点要小于根，右节点所有节点要大于根节点，左右节点也要符合
所以min是最小值，不能比这个小，max是最大值，不能比这个大。
```
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isValidBST(root *TreeNode) bool {
    if root == nil{
        return true
    }
    return isBST(root,math.MinInt64,math.MaxInt64)
}

func isBST(root *TreeNode,left, right int) bool{
    if root == nil{
        return true
    }
    if left >= root.Val || right <= root.Val{
        return false
    }
    return isBST(root.Left,left,root.Val) && isBST(root.Right,root.Val,right)
}
```
