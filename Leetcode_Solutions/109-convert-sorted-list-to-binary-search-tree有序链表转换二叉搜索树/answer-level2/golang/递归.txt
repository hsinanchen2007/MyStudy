### 解题思路
把链表中间的元素作为树的根节点,左子链表用来构造左子树,右子链表用来构造右子树.

### 代码
1. 使用切片复制链表元素再构造二叉树
```golang
func sortedListToBST(head *ListNode) *TreeNode {
	ints := make([]int, 0)
	p := head
	for p != nil {
		ints = append(ints, p.Val)
		p = p.Next
	}
	return buildTreeWithSlice(ints, 0, len(ints)-1)
}
func buildTreeWithSlice(ints []int, left, right int) *TreeNode {
	if left > right {
		return nil
	}
	mid := (left + right) / 2
	root := &TreeNode{
		Val:   ints[mid],
		Left:  buildTreeWithSlice(ints, left, mid-1),
		Right: buildTreeWithSlice(ints, mid+1, right),
	}
	return root
}

```

2. 原地构造二叉树
```golang
func sortedListToBST(head *ListNode) *TreeNode {
	return buildTree(head)
}

func buildTree(head *ListNode) *TreeNode {
	if head == nil {
		return nil
	}
	var leftTail *ListNode = nil
	rightTail := head
	rootNode := head
	for rightTail != nil && rightTail.Next != nil {
		rightTail = rightTail.Next.Next
		leftTail = rootNode
		rootNode = rootNode.Next
	}
	if leftTail == nil {
		return &TreeNode{
			Val:   head.Val,
			Left:  nil,
			Right: nil,
		}
	}
	leftTail.Next = nil
	root := &TreeNode{
		Val:   rootNode.Val,
		Left:  buildTree(head),
		Right: buildTree(rootNode.Next),
	}
	return root
}
```