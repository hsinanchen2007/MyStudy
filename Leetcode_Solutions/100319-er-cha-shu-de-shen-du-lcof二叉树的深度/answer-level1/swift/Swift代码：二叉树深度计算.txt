```
func maxDepth(_ root: TreeNode?) -> Int {
    if root == nil {
        return 0
    }
    let depth = max(maxDepth(root!.left), maxDepth(root!.right)) + 1
    return depth
}

```
