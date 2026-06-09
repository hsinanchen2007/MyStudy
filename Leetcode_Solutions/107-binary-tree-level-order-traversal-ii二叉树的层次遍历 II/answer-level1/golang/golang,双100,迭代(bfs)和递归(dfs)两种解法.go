先顺序遍历,后翻转结果集

**迭代解法**
![image.png](https://pic.leetcode-cn.com/2b8c91dedc06839e15cd9ebe46fb38cf0f5928814a6762de9387344a0e54b3b6-image.png)
```
func levelOrderBottom(root *TreeNode) [][]int {
	//广度优先搜索(bfs)
	result := make([][]int, 0)
	level := 0
	if root == nil {
		return result
	}

	//初始化队列
	list := []*TreeNode{root}
	length := 1 //队列长度(即当前层节点数)
	for length > 0 {
		//从队列中取出当前层
		for i := 0; i < length; i++ {
			//出队
			node := list[0]
			list = list[1:]

			//值放入result
			if len(result) > level {
				result[level] = append(result[level], node.Val)
			} else {
				result = append(result, []int{node.Val})
			}

			//下一层入队
			if node.Left != nil {
				list = append(list, node.Left)
			}
			if node.Right != nil {
				list = append(list, node.Right)
			}
		}

		length = len(list)
		level++
	}

	//数组翻转
	resultLength := len(result)
	left := 0
	right := resultLength - 1
	for left < right {
		temp := result[left]
		result[left] = result[right]
		result[right] = temp

		left++
		right--
	}

	return result
}
```


**递归解法**
![image.png](https://pic.leetcode-cn.com/751b1ac168f447acf01e4b6bda067f1ccdc08c6746b5bfe588eb61079091fced-image.png)
```
func levelOrderBottom(root *TreeNode) [][]int {
	//深度优先遍历(dfs)
	result := make([][]int, 0)
	level := 0
	if root == nil {
		return result
	}

	orderBottom(root, &result, level)

	//数组翻转
	resultLength := len(result)
	left := 0
	right := resultLength - 1
	for left < right {
		temp := result[left]
		result[left] = result[right]
		result[right] = temp

		left++
		right--
	}

	return result
}

func orderBottom(root *TreeNode, result *[][]int, level int) {
	if root == nil {
		return
	}

	if len(*result) > level {
		(*result)[level] = append((*result)[level], root.Val)
	} else {
		*result = append(*result, []int{root.Val})
	}

	orderBottom(root.Left, result, level+1)
	orderBottom(root.Right, result, level+1)
}
```
