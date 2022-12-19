### 解题思路
两个办法
1. 递归
### 代码

```
func inorderTraversal(root *TreeNode) []int {
	result := make([]int, 0)
	_inorderTraversal(root, &result)
	return result
}

func _inorderTraversal(node *TreeNode, result *[]int) {
	// terminal
	if node == nil {
		return
	}
	// current logic
	// drill down
	_inorderTraversal(node.Left, result)
	*result = append(*result, node.Val)
	_inorderTraversal(node.Right, result)
}
```

2. 遍历:树的循环一般根据不同情况采用栈和队列, 这里采用栈来解决、只要left不为空、就一直入栈、然后检查出栈节点的right是否为空、如果不为空、right入栈、继续前面的步骤、退出条件、栈为空或者当前节点为空
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

func inorderTraversal(root *TreeNode) []int {
	stack := []*TreeNode{}
	result := make([]int, 0)
	var cur_node = root
	for len(stack) != 0 || cur_node != nil{
		for cur_node != nil {
			stack = append(stack, cur_node)
			cur_node = cur_node.Left
		}
		stack, cur_node = pop(stack) // 左节点为空了、出栈
		result = append(result, cur_node.Val)
		cur_node = cur_node.Right
	}
	return result
}

func pop(stack []*TreeNode) ([]*TreeNode, *TreeNode) {
	if len(stack) == 0 {
		return nil, nil
	}
	return stack[:len(stack) - 1], stack[len(stack)-1]
}
```
