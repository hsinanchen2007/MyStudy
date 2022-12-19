### 解题思路
如下代码所示

### 代码

```golang
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Left *Node
 *     Right *Node
 *     Next *Node
 * }
 */

func connect(root *Node) *Node {
	if root == nil || (root.Left == nil && root.Right == nil) {
		return root
	}
	
	// 左子结点不为空时存在两种情况: 1. 当右子结点不为空时，左子结点的Next就为右子结点
	if root.Left != nil {
		root.Left.Next = root.Right
	}
    // 2. 当右子结点为空时，统一对其进行处理
	var lastNode = root.Right
	if lastNode == nil {
		lastNode = root.Left
	}
	var nextNode = root.Next
	for nextNode != nil && (nextNode.Left == nil && nextNode.Right == nil) {
		nextNode = nextNode.Next
	}
	if nextNode != nil {
		if nextNode.Left != nil {
			lastNode.Next = nextNode.Left
		} else {
			lastNode.Next = nextNode.Right
		}
	}
	
    // 必须先对右子结点进行处理，不然左子结点的Next可能会找不到
	connect(root.Right)
	connect(root.Left)

	return root
}
```