- 使用双向队列 https://golang.org/pkg/container/list/
- 每层遍历的时候，队列长度即是上一层的元素个数listLength，使用尾部移除，头部插入的方式，每次尾部移除listLength个元素。
- 结果数组append的时候，每次将已有结果append到当前层结果之后，`result = append([][]int{currentLevel}, result...)`

```
func levelOrderBottom(root *TreeNode) [][]int {
	var result [][]int
	if root == nil {
		return result
	}
    // 使用双向队列
	list := list.New()
    // 头部插入
	list.PushFront(root)
    // 进行广度搜索
	for list.Len() > 0 {
		var currentLevel []int
		listLength := list.Len()
		for i := 0; i < listLength; i++ {
            // 尾部移除
			node := list.Remove(list.Back()).(*TreeNode)
			currentLevel = append(currentLevel, node.Val)
			if node.Left != nil {
				list.PushFront(node.Left)
			}
			if node.Right != nil {
				list.PushFront(node.Right)
			}
		}
        result = append([][]int{currentLevel}, result...)

	}
	return result
}
```
