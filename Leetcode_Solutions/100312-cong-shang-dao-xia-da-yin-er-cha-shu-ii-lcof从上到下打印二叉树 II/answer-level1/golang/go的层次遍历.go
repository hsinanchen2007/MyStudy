**菜鸡思路**
```
1. nodeQueue存节点
2. levelQueue存层数

不知道我菜，还是我菜，代码量这么大！
```
** 代码**

```
func levelOrder(root *TreeNode) [][]int {
	if root == nil{
		return [][]int{}
	}
	var result = make([][]int,0)
	var nodeQueue = []*TreeNode{root}
	var levelQueue = []int{0}
	var tempLevel int
	var tempNode *TreeNode
	var tempSlice = make([]int,0)
	var curLevel = 0
	for len(nodeQueue) != 0 {
		tempNode,tempLevel = nodeQueue[0],levelQueue[0]
		if tempLevel != curLevel{
			result = append(result, tempSlice)
			curLevel = tempLevel
			tempSlice = make([]int,0)
		}
		if tempLevel == curLevel{
			tempSlice = append(tempSlice, tempNode.Val)
		}
		nodeQueue,levelQueue = nodeQueue[1:],levelQueue[1:]
		if tempNode.Left != nil {
			nodeQueue = append(nodeQueue, tempNode.Left)
			levelQueue = append(levelQueue, curLevel+1)
		}
		if tempNode.Right != nil {
			nodeQueue = append(nodeQueue, tempNode.Right)
			levelQueue = append(levelQueue, curLevel+1)
		}
	}
    result = append(result, tempSlice)
	return result
}
```
