```go
/**
深度优先遍历
时间复杂度：O(n)
空间复杂度：O(n)
 */
func levelOrder(root *TreeNode) [][]int {
    var res [][]int
    var _dfs func(root *TreeNode, level int)
    _dfs = func(root *TreeNode, level int) {
        if root == nil {
            return
        }
        if level == len(res) {
            res = append(res, []int{})
        }
        res[level] = append(res[level], root.Val)

        _dfs(root.Left, level + 1)
        _dfs(root.Right, level + 1)
    }

    _dfs(root, 0)
    return res
}

/**
广度优先遍历
时间复杂度：O(n)
空间复杂度：O(n)
 */
func levelOrder(root *TreeNode) [][]int {
    var res [][]int
    if root == nil {
        return res
    }
    //双向队列
    list := list.New()
    //头部插入
    list.PushFront(root)
    //进行广度搜索
    for list.Len() > 0  {
        var currentLevel []int
        listLength := list.Len()
        for i := 0; i < listLength; i++  {
            //尾部移除
            node := list.Remove(list.Back()).(*TreeNode)
            currentLevel = append(currentLevel, node.Val)
            if node.Left != nil {
                list.PushFront(node.Left)
            }
            if node.Right != nil {
                list.PushFront(node.Right)
            }
        }
        res = append(res, currentLevel)
    }
    return res
}

```