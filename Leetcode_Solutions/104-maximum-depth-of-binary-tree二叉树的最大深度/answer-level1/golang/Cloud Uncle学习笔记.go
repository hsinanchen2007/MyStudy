左子树的高度和右子树高度的较大值
```
func maxDepth(root *TreeNode) int {
    //terminator
    if root == nil {
        return 0
    }

    //prcess logic of current level
    left := maxDepth(root.Left)
    right := maxDepth(root.Right)

    //drill down

    //reverse
    if left >= right {
        return left + 1
    }

    return right + 1    
}
```
