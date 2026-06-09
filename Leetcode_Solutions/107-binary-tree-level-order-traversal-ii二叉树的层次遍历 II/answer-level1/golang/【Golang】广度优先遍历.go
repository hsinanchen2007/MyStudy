

1. 使用 []*TreeNode 的数组保存每一层所有的节点
2. 保存整棵树的是：[][]*TreeNode

如何保存整层树？

1. 使用广度优先遍历 + 队列

Data := [][]*TreeNode  // 保存整棵树
Data[0] = []*TreeNode{root}  // 第0层，也即只有一个节点root

开始遍历：

    从 0 层开始遍历，拿出第0层所有数据，Data[0]，

    开始遍历Data[0]中的所有元素（[]*TreeNode），使用广度优先，

    生成新的[]*TreeNode，添加到Data中。

层次遍历结束条件是：已经遍历完Data的第1个维度，即没有更多层。


```
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func levelOrderBottom(root *TreeNode) [][]int {
    if root == nil {
		return nil
	}


    Data := make([][]*TreeNode, 0, 8)  // 保存整棵树
    Data = append(Data, []*TreeNode{root}) // 第0层，只有一个节点root


	level := 0
	for {
		// for 每次循环是遍历一层数据
		// 每一次循环会生成一批节点，添加到Data中，作为下一层节点的数据

		if level >= len(Data) {
			// 没有更多层
			break
		}

		// 当前层的所有节点
		levelNodes := Data[level]
		
		// 遍历当前层的所有节点，使用广度优先生成下一层的节点，
		//
		// 下一层节点数最多为：
		// level为当前层，从0开始，那么当前层节点数最多为 2^n
		// 所以下一层节点数最多为2^(n+1)
        
        // 使用数的最大节点数优先申请内存空间，会导致leetcode报内存分配报错
        // currentLevelMaxCount := 2<<uint(level+1)
        // nextLevelNodes := make([]*TreeNode, 0, currentLevelMaxCount)
        
        nextLevelNodes := make([]*TreeNode, 0, 32)
		for j := 0; j < len(levelNodes); j++ {
			node := levelNodes[j]

			if node.Left != nil {
				nextLevelNodes = append(nextLevelNodes, node.Left)
			}

			if node.Right != nil {
				nextLevelNodes = append(nextLevelNodes, node.Right)
			}
		}

		// 如果nextLevelNode有数据，则增加到Data里面，
		// 否则不增加，那么下一轮循环就会跳出循环
		if len(nextLevelNodes) != 0 {
			Data = append(Data, nextLevelNodes)
		}

		level++ // 继续下一层
	}


	// 现在Data保存的数据状态是：
	// 按层保存整棵数，每一层都是N个节点，即[]*TreeNode

	
	// 输出结果
	result := make([][]int, 0, len(Data))

	// 从底层开始输出
	for i := len(Data)-1; i >= 0; i-- {

		currentLevel := Data[i]

		nums := make([]int, len(currentLevel))

		for j := 0; j < len(currentLevel); j++ {
			nums[j] = currentLevel[j].Val
		}

		result = append(result, nums)
	}

	return result
}
```




**结果：**

执行用时 :4 ms, 在所有 Go 提交中击败了86.43%的用户
内存消耗 :6 MB, 在所有 Go 提交中击败了86.21%的用户