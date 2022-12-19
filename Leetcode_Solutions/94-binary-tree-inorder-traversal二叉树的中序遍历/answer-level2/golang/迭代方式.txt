
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
    result := make([]int,0,0)
	stack := NewStack()
	treeNode := root
	for treeNode != nil || !stack.Empty() {
		for treeNode != nil {
			stack.Push(treeNode)
			treeNode = treeNode.Left
		}
		if !stack.Empty() {
			node := stack.Pop()
			result = append(result, node.Val)
			treeNode = node.Right
		}
	}

	return result
}

type Stack struct {
	index int
	elements []*TreeNode
}

func NewStack() *Stack {
	return &Stack{index:-1,elements:make([]*TreeNode,0,0)}
}

func (this *Stack) Pop() *TreeNode {
	if this.index <  0 {
		return nil
	}
	node := this.elements[this.index]
	this.index--
	return node
}

func (this *Stack) Push(treeNode *TreeNode) {
	this.index++
	if this.index >= len(this.elements) {
		this.elements = append(this.elements, treeNode)
	}else {
		this.elements[this.index] = treeNode
	}
}

func (this *Stack) Empty() bool {
	return this.index == -1
}
```