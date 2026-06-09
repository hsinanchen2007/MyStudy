自己初学go,代码有很多不合理的地方，
望大佬指正，阿里嘎到

```
if root == nil {
		return []int{}
	}
	var result = make([]int,0)
	var nodeQueue = []*TreeNode{root}
	var levelQueue = []int{0}
	var curLevel int
	for len(nodeQueue) != 0{
		var tempNode,tempLevel = nodeQueue[0],levelQueue[0]
		if curLevel != tempLevel{
			curLevel = tempLevel
		}
		if curLevel == tempLevel{
			result = append(result, tempNode.Val)
		}
		nodeQueue = nodeQueue[1:]
		levelQueue = levelQueue[1:]
		if tempNode.Left != nil {
			nodeQueue = append(nodeQueue, tempNode.Left)
			levelQueue = append(levelQueue,curLevel+1)
		}
		if tempNode.Right != nil {
			nodeQueue = append(nodeQueue, tempNode.Right)
			levelQueue = append(levelQueue,curLevel+1)
		}

	}
	return result
}
```
