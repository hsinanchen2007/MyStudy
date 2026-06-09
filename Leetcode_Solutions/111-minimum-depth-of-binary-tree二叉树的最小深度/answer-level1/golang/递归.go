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
func minDepth(root *TreeNode) int {
    if root == nil {
        return 0
    }
    if root.Left == nil && root.Right == nil {
        return 1
    }
    if root.Left ==nil || root.Right == nil {
        return 1 + max(minDepth(root.Left), minDepth(root.Right))
    }

    return 1 + min(minDepth(root.Left), minDepth(root.Right))
}

func min(i,j int) int {
    if i > j {
        return j
    }
    return i
}
func max(i,j int) int {
    if i < j {
        return j
    }
    return i
}
```