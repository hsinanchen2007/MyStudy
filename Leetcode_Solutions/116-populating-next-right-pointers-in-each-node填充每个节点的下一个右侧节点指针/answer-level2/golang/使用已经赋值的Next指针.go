### 解题思路
1. 由于是完美二叉树，对当前结点判空
2. 当前结点的左子结点的Next结点指向当前结点的右子结点
3. 如果当前结点的Next指针不为空，则当前结点的右子结点的Next指针指向当前结点的Next结点的左子结点

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
	if root == nil || root.Left == nil || root.Right == nil {
		return root
	}
	
	root.Left.Next = root.Right
	if root.Next != nil {
		root.Right.Next = root.Next.Left
	}
	
	connect(root.Left)
	connect(root.Right)

    return root
}
```