```
type BSTIterator struct {
	queue []int
	index int
}

func Constructor(root *TreeNode) BSTIterator {
	return BSTIterator{
		queue: helperBSTIterator(root),
		index: 0,
	}
}
//迭代
func helperBSTIterator(root *TreeNode) []int {
	nums, stack := make([]int, 0), make([]*TreeNode, 0)
	for root != nil || len(stack) != 0 {
		for root != nil {
			stack = append(stack, root)
			root = root.Left
			continue
		}
		nums = append(nums, stack[len(stack)-1].Val)
		root = stack[len(stack)-1].Right
		stack = stack[:len(stack)-1]
	}
	return nums
}

func (this *BSTIterator) Next() int {
	val := this.queue[this.index]
	this.index++
	return val
}

func (this *BSTIterator) HasNext() bool {
	return this.index < len(this.queue)
}
```
