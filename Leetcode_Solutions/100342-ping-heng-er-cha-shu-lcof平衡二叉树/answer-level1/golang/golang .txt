### 解题思路
后序遍历；递归

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
func isBalanced(root *TreeNode) bool {
    if root == nil {
        return true
    }

    lh := isBalanced(root.Left)
    rh := isBalanced(root.Right)
    d := abs(height(root.Left), height(root.Right))
    return d <= 1 && lh && rh
}

func height(root *TreeNode) int {
    if root == nil {
        return 0
    }
    lh := height(root.Left) + 1
    rh := height(root.Right) + 1
    return max(lh, rh)
}

func max(x, y int) int {
    if x > y {
        return x
    }
    return y
}

func abs(x, y int) int {
    if x - y > 0 {
        return x - y
    }
    return y - x
}
```