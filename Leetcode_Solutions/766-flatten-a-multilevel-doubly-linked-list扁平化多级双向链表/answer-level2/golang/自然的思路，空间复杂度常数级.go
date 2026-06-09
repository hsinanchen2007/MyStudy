### 解题思路
遍历链表，遇到child就将其插入当前节点和下一个节点之间
假设节点总数为n，时间复杂度为O(n), 空间复杂度O(1)

### 代码

```golang
func flatten(root *Node) *Node {
	for p := root; p != nil; p = p.Next {
		if p.Child == nil {
			continue
		}
		next := p.Next
		p.Next, p.Child.Prev = p.Child, p
		q := p.Child
		for q.Next != nil {
			q = q.Next
		}
		q.Next = next
		if next != nil {
			next.Prev = q
		}
		p.Child = nil
	}
	return root
}
```