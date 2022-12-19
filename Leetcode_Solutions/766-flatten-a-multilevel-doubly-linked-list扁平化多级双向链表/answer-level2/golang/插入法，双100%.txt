思路：遇到child链表就将其插入到cur节点和next节点之间，并将child链表改成双向链表；这样循环直到末尾
```
func flatten(root *Node) *Node {
    if root == nil {
        return nil
    }

    cur := root
	for cur != nil {
		next := cur.Next
		if cur.Child != nil {
			// 存在child节点，将child与cur节点之间的chil链表改成双向链表
			child := cur.Child
			cur.Next = child
			child.Prev = cur
			cur.Child = nil
			// 获取child这一段子链表的尾节点，以便插入到cur的后面和next前面
			tail := child
			for tail != nil && tail.Next != nil {
				tail = tail.Next
			}
			// 将[child, tail]这一段子链表插入到cur和next之间的位置
			tail.Next = next
			if next != nil {
				next.Prev = tail
			}
		}
		cur = cur.Next
	}
	return root
}

```
