### 解题思路
注意递归的定义

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
func sumNumbers(root *TreeNode) int {
    return sumNumbersWithPrefix(root, 0)
}

// prefix 表示根节点到root节点（不包括root节点）上的节点的路径总和
func sumNumbersWithPrefix(root *TreeNode, prefix int) int {
    if root == nil {
        return 0
    }
    //每次遇到一个非空的节点，更新路径和。提前计算号，避免后面重复计算。
    curSum := prefix * 10 + root.Val
    if root.Left == nil && root.Right == nil {
        return curSum
    }
    var left, right int
    left = sumNumbersWithPrefix(root.Left, curSum)
    right = sumNumbersWithPrefix(root.Right, curSum)
    return left + right
    
}
```