```
type queueNode struct {
	node  *TreeNode
	depth int
}

func listOfDepth(tree *TreeNode) []*ListNode {
	if tree == nil {
		return nil
	}

	var result []*ListNode
	var queue []queueNode
	queue = append(queue, queueNode{tree, 1})

	for len(queue) > 0 {
		node := queue[0]
		queue = queue[1:]
		if len(result) < node.depth {
			result = append(result, &ListNode{Val: node.node.Val})
		} else {
			head := result[len(result)-1]
			for head.Next != nil {
				head = head.Next
			}
			head.Next = &ListNode{Val: node.node.Val}
		}
		if node.node.Left != nil {
			queue = append(queue, queueNode{node.node.Left, node.depth + 1})
		}
		if node.node.Right != nil {
			queue = append(queue, queueNode{node.node.Right, node.depth + 1})
		}
	}

	return result
}
```
