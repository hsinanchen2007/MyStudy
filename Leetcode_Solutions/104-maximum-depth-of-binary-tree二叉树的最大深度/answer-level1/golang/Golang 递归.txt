### 运行结果
执行结果: 通过
执行用时: 4 ms, 在所有 Go 提交中击败了92.42%的用户
内存消耗: 4.4 MB, 在所有 Go 提交中击败了59.59%的用户

### 解题思路
对左子树和右子树进行递归处理。

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
    leftDepth := maxDepth(root.Left)
    rightDepth := maxDepth(root.Right)
    if leftDepth < rightDepth {
        return 1 + rightDepth
    } 
    return 1 + leftDepth
}
```