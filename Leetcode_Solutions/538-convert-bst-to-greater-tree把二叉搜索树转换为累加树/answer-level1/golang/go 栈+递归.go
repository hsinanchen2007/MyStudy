```
//go 栈解法
type Node struct {
	Tree *TreeNode
	Next *Node
}
type stack struct {
	pre *Node
}

func (s *stack) push(x *TreeNode) {
	node := &Node{x, nil}
	node.Next = s.pre.Next
	s.pre.Next = node
}
func (s *stack) pop() *TreeNode {
	v := s.pre.Next.Tree
	s.pre.Next = s.pre.Next.Next
	return v
}
func (s *stack) peek() *TreeNode {
	return s.pre.Next.Tree
}

func (s *stack) empty() bool {
	return s.pre.Next == nil
}
func construct() *stack {
	return &stack{&Node{}}
}

func convertBST(root *TreeNode) *TreeNode {
	if root == nil {
		return root
	}
	node := root
	stack := construct()
	sum := 0
	for !stack.empty() || node != nil {
		for node != nil {
			stack.push(node)
			node = node.Right
		}
		node = stack.pop()
		sum += node.Val
		node.Val = sum
		node = node.Left
	}
	return root
}
```

```
//递归解法
func dfs(root *TreeNode, nums *int) *TreeNode {
	if root != nil {
		dfs(root.Right, nums)
		*nums += root.Val
		root.Val = *nums
		dfs(root.Left, nums)
	}
	return root
}
func convertBST(root *TreeNode) *TreeNode {
	nums := 0

	dfs(root, &nums)
	return root
}
```

