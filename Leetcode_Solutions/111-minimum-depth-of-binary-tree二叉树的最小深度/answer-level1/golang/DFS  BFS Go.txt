```go
/**
DFS
时间复杂度：O(n)
空间复杂度：O(n)
 */
func minDepth(root *TreeNode) int {
    switch {
    case root == nil:
        return 0
    case root.Left == nil:
        return minDepth(root.Right) + 1
    case root.Right == nil:
        return minDepth(root.Left) + 1
    default:
        return min(minDepth(root.Left), minDepth(root.Right)) + 1
    }
}

/**
BFS
时间复杂度：O(n)
空间复杂度：O(n)
 */
func minDepth(root *TreeNode) int {
    if root == nil {
        return 0
    }
    depth := 0
    //创建队列
    list := list.New()
    //头部插入
    list.PushFront(root)
    //进行广度搜索
    for list.Len() > 0 {
        depth++
        currentLength := list.Len()
        for i := 0; i < currentLength; i++ {
            //尾部移除
            node := list.Remove(list.Back()).(*TreeNode)
            if node.Left == nil && node.Right == nil {
                return depth
            }
            if node.Left != nil {
                list.PushFront(node.Left)
            }
            if node.Right != nil {
                list.PushFront(node.Right)
            }
        }
    }
    return depth
}
```