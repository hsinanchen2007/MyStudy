先计算叶子节点的深度。
```
leftDepth, left := lt(root.Left, depth + 1)
rightDepth, right := lt(root.Right, depth + 1)
```
对左右节点的值进行判断即可

如果左右叶子节点深度相同，则公共祖先为当前节点。否则为深度更大的节点

```
func lcaDeepestLeaves(root *TreeNode) *TreeNode {
    _, ret := lt(root, 0)
    return ret
}

func lt(root *TreeNode, depth int) (int, *TreeNode) {
    if root == nil {
        return -1, nil
    }
    leftDepth, left := lt(root.Left, depth + 1)
    rightDepth, right := lt(root.Right, depth + 1)
    if left == nil && right == nil {
        return depth + 1, root
    }
    if leftDepth == rightDepth{ 
        return leftDepth, root
    } else if leftDepth > rightDepth {
        return leftDepth, left
    }
    return rightDepth, right
}
```
