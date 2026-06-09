```
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */


type Stack struct {
	vals []interface{}
}

func InitStack() *Stack {
	return &Stack{}
}

func (s *Stack) Pop() interface{} {
	if len(s.vals) == 0 {
		return nil
	}
	end := len(s.vals) - 1
	result := s.vals[end]
	s.vals = s.vals[:end]

	return result
}

func (s *Stack) Push(val interface{}) {
	s.vals = append(s.vals, val)
}


func preorderTraversal(root *TreeNode) []int {
	res := []int{}
	if root == nil {
		return res
	}

	stack := InitStack()
	stack.Push(root)

	for {
		node := stack.Pop()
		if node == nil {
			break
		}
		res = append(res, node.(*TreeNode).Val)

	    right := node.(*TreeNode).Right
		if right != nil {
			stack.Push(right)
		}

		left := node.(*TreeNode).Left
		if left != nil {
			stack.Push(left)
		}
	}

	return res
}
```
