### 解题思路
递归查找即可

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
func searchBST(root *TreeNode, val int) *TreeNode {
    if root == nil {
        return nil
    }
    if val > root.Val {
        return searchBST(root.Right, val)
    } else if val < root.Val {
        return searchBST(root.Left, val)
    } else {
        return root
    }
    return nil
}
```