用栈需要额外的空间，如果用莫里斯方法的话，可以不用多余的空间

```
import (
	"container/list"
)

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
const (
	TypeNode  = 1
	TypeValue = 2
)

type QueueElem struct {
	Type  int
	Value *TreeNode
}
type BSTIterator struct {
	queue *list.List
}

func Constructor(root *TreeNode) (i BSTIterator) {
	i = BSTIterator{
		queue: list.New(),
	}
	if root != nil {
		i.pushNode(root)
	}
	return
}

/** @return the next smallest number */
func (this *BSTIterator) Next() int {
	elem := this.queue.Remove(this.queue.Back()).(QueueElem)
	for elem.Type != TypeValue {
		this.pushNode(elem.Value)
		elem = this.queue.Remove(this.queue.Back()).(QueueElem)
	}
	return elem.Value.Val
}

/** @return whether we have a next smallest number */
func (this *BSTIterator) HasNext() bool {
	return this.queue.Len() != 0
}

/** @return whether we have a next smallest number */
func (this *BSTIterator) pushNode(root *TreeNode) {
	if root.Right != nil {
		this.queue.PushBack(QueueElem{
			Type:  TypeNode,
			Value: root.Right})
	}
	this.queue.PushBack(QueueElem{
		Type:  TypeValue,
		Value: root,
	})
	if root.Left != nil {
		this.queue.PushBack(QueueElem{
			Type:  TypeNode,
			Value: root.Left,
		})
	}
}
```
