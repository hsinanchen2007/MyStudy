### 解题思路
此处撰写解题思路

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
type Queue struct {
	list.List
}

func (q *Queue) Push(val *TreeNode) {
	q.PushFront(val)
}

func (q *Queue) Pop() *TreeNode {
	return q.List.Remove(q.List.Back()).(*TreeNode)
}

func (q *Queue) Len() int {
	return q.List.Len()
}

func levelOrder(root *TreeNode) [][]int {
	res := make([][]int, 0, 128)
    if root== nil {
        return res
    }
	queue1 := &Queue{}
	queue2 := &Queue{}
	queue1.Push(root)
	for queue1.Len() != 0 || queue2.Len() != 0 {

		tmp := make([]int, 0, 8)
		for queue1.Len() != 0 {
			node := queue1.Pop()
			if node.Left != nil {
				queue2.Push(node.Left)
			}
			if node.Right != nil {
				queue2.Push(node.Right)
			}
			tmp = append(tmp, node.Val)
		}
		if len(tmp) != 0 {
			res = append(res, tmp)
		}

		tmp2 := make([]int, 0, 8)
		for queue2.Len() != 0 {
			node := queue2.Pop()
			if node.Left != nil {
				queue1.Push(node.Left)
			}
			if node.Right != nil {
				queue1.Push(node.Right)
			}
			tmp2 = append(tmp2, node.Val)
		}
		if len(tmp2) != 0 {
			res = append(res, tmp2)
		}
	}
	return res
}
```