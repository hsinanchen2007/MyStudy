题目不难，理解题目比较难。

题意是：找到所有叶子节点深度相等的最深根节点
具体见注释
```
func subtreeWithAllDeepest(root *TreeNode) *TreeNode {
    _, ret := subtree(root)
    return ret
}

func subtree(root *TreeNode) (int, *TreeNode) {
    if root == nil {
        return 0, nil
    }
    leftDepth, left := subtree(root.Left) // 左深度
    rightDepth, right := subtree(root.Right) // 右深度
    if leftDepth == rightDepth { // 如果左右相等，说明符合要求，深度加一
        return leftDepth + 1, root
    }
    // 如果不想等，只能返回左右节点中较深的一个
    if leftDepth > rightDepth { 
        return leftDepth + 1, left
    }
    return rightDepth + 1, right
}
```