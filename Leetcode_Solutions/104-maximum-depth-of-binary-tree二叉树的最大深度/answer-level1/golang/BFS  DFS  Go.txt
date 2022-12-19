```go
/**
DFS
时间复杂度: O(n)
空间复杂度: O(n)
*/
func maxDepth(root *TreeNode) int {
    if root == nil {
        return 0
    }
    return max(maxDepth(root.Left), maxDepth(root.Right)) + 1
}

func max(a int, b int) int {
    if a > b {
        return a
    }
    return b
}

/**
BFS
时间复杂度: O(n)
空间复杂度: O(n)
*/
func maxDepth(root *TreeNode) int {
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
        currentLength := list.Len()
        for i := 0; i < currentLength; i++ {
            //尾部移除
            node := list.Remove(list.Back()).(*TreeNode)
            if node.Left != nil {
                list.PushFront(node.Left)
            }
            if node.Right != nil {
                list.PushFront(node.Right)
            }
        }
        depth++
    }
    return depth
}

```