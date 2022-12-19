1.递归
```
func minDepth(root *TreeNode) int {
    //1.根节点为nil的情况，整棵树的深度就为0
    if root == nil {
        return 0
    }
    //2.左子树和右子树都为空的情况，说明整棵树只有根节点，返回深度为1
    if root.Left == nil && root.Right == nil {
        return 1
    }
    //3.左子树为nil的时候，那就要计算右子树的最小深度，然后+1
    if root.Left == nil {
        return minDepth(root.Right) + 1
    }
    //4.右子树为nil的时候，那就要计算左子树的最小深度，然后+1
    if root.Right == nil {
        return minDepth(root.Left) + 1
    }

    //5.当左右子树都不为nil的时候，就要计算左右子树中的较小深度，然后+1
    return min(minDepth(root.Left), minDepth(root.Right)) + 1

}

func min(a, b int) int {
    if a <= b {
        return a
    }

    return b
}
```
