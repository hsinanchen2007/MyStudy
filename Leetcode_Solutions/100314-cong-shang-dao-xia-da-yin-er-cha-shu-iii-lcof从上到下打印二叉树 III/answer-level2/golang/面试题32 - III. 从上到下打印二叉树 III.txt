### 解题思路
干就完了 奥利给！

### 代码

```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func levelOrder(root *TreeNode) [][]int {
	if root == nil {
		return [][]int{}
	}
	queue := []*TreeNode{root}
	result := [][]int{}
	flag := 0
	for len(queue) > 0 {
		count := len(queue)
		temp := []int{}
		for i := 0; i < (count); i++ {
			root := queue[0]
			queue = queue[1:]
			if root.Left != nil {
				queue = append(queue, root.Left)
			}
			if root.Right != nil {
				queue = append(queue, root.Right)
			}
			temp = append(temp, root.Val)
		}
		if flag%2 == 0 {
			result = append(result, temp)
		} else {
			// temp数据倒叙   123  321
			ttmp := []int{}
			for k := len(temp)-1; k >= 0; k-- {
				ttmp = append(ttmp,temp[k])
			}
			result = append(result, ttmp)
		}
		flag++

	}
	return result
}

```