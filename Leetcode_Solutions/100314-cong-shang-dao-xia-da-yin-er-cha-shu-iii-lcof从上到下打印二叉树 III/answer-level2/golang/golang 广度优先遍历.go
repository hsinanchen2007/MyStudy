
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
	var res [][]int
	if root == nil {
		return res
	}
	queue := list.New()
	queue.PushFront(root)
	for queue.Len() > 0 {
		length := queue.Len()
		var middle []int
		for i := 0; i < length; i++ {
			node := queue.Remove(queue.Back()).(*TreeNode)
			if len(res)&1 == 0 {
				middle = append(middle, node.Val)
			} else {
				middle = addByIndex(middle, 0, node.Val)
			}
			if node.Left != nil {
				queue.PushFront(node.Left)
			}
			if node.Right != nil {
				queue.PushFront(node.Right)
			}
		}
		res = append(res, middle)
	}
	return res
}

func addByIndex(s []int, index int, val int) []int {
	s = append(s, 0)
	copy(s[index+1:], s[index:])
	s[index] = val
	return s
}
```