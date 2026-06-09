**思路**

```
1. LevelNode结构体 :记录遍历的节点+该节点层次
2. reverseSlice函数：用于奇偶层次翻转


1. 记录层次！=当前层次  ： 添加slice记录-->结果,更新层次,声明新的slice
2. 记录层次==当前层次   ：slice添加记录
```

**代码**

```
type LevelNode struct {
		node *TreeNode
		level int
	}

	func reverseSlice(nums []int)  {
		for i:=0;i<len(nums) ;i++  {
			nums[i],nums[len(nums)-i-1] = nums[len(nums)-i-1],nums[i]
		}
	}

	func levelOrder(root *TreeNode) [][]int {
		if root == nil{
			return make([][]int,0)
		}
		var result = make([][]int,0)
		var tempResult = make([]int,0)
		tempResult = append(tempResult, root.Val)

		var queue = make([]LevelNode,0)
		queue = append(queue, LevelNode{
			node:  root,
			level: 0,
		})
		var curLevel = -1
		for len(queue) != 0 {
			var tempNode,tempLevel = queue[0].node,queue[0].level
			queue = queue[1:]
			if curLevel != tempLevel{
				if curLevel%2 == 1{
					reverseSlice(tempResult)
				}
				result = append(result, tempResult)
				tempResult = make([]int,0)
				curLevel++
			}
			if curLevel == tempLevel{
				tempResult = append(tempResult, tempNode.Val)
			}
			if tempNode.Left != nil{
				queue = append(queue, LevelNode{
					node:  tempNode.Left,
					level: tempLevel+1,
				})
			}
			if tempNode.Right != nil{
				queue = append(queue,LevelNode{
					node:  tempNode.Right,
					level: tempLevel+1,
				})
			}
		}
		if curLevel%2 == 1{
			reverseSlice(tempResult)
		}
		result = append(result, tempResult)
		return result
	}
```
