1.找终止条件：树为空的时候，此时树的深度为0，递归就结束了。

2.找返回值：需要从每一级得到的是当前这一级对应的树的最大深度，因此返回值应该是当前树的最大深度。

3.本层递归应该做什么：三个节点：root、root.left、root.right，根据第二步，root.left和root.right分别记录的是root的左右子树的最大深度。那么本层递归应该是在root的左右子树中选择较大的一个，再加上1就是以root为根的子树的最大深度，然后再返回这个深度。

```
func maxDepth(root *TreeNode) int {
    if root == nil {
        return 0
    }
    leftMax := maxDepth(root.Left)
    rightMax := maxDepth(root.Right)
    return int(math.Max(float64(leftMax), float64(rightMax)) + 1)
}
```
