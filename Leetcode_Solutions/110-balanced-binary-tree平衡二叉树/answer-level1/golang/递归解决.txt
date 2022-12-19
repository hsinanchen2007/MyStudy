**思路**
递归函数内部分别计算左右子树最大深度和判断是否是平衡树，然后比较两个子树深度并返回当前树的深度和是否平衡二叉树布尔值。

**参考代码**
```
func getDepths(root *TreeNode) (int, bool) {
    if root == nil {
        return 0, true
    }
    leftDepth, leftAvl := getDepths(root.Left)
    rightDepth, rightAvl := getDepths(root.Right)
    if root.Left != nil {
        leftDepth++
    }
    if root.Right != nil {
        rightDepth++
    }

    depth := leftDepth
    if leftDepth < rightDepth {
        depth = rightDepth
    }

    if !leftAvl || !rightAvl || int(math.Abs(float64(leftDepth-rightDepth))) > 1 {
        return depth, false
    }
    return depth, true
}

func isBalanced(root *TreeNode) bool {
    _, ans := getDepths(root)
    return ans
}
```
