### 解题思路
此处撰写解题思路

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
// 递归中序遍历
var x, y, prev *TreeNode
func recoverTree(root *TreeNode)  {
    x, y, prev = nil, nil, nil
    findTwoWrong(root)
    if x != nil && y != nil {
        x.Val, y.Val = y.Val,x.Val
    }
}

func findTwoWrong(root *TreeNode) {
    if root == nil {
        return
    }

    findTwoWrong(root.Left)
    if prev != nil && root.Val < prev.Val {
        y = root
        if x == nil {
            x = prev
        }
    }
    prev = root
    findTwoWrong(root.Right)
}
```