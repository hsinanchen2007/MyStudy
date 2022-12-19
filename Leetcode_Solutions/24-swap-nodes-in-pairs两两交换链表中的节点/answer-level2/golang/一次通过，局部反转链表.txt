![3CB0C1EE-65C5-43de-80C7-88CCE5AB269E.png](https://pic.leetcode-cn.com/d7a2e211e6a963bd422c54d5fd011506f51d4e833b0dadfd9d091bc4654ae400-3CB0C1EE-65C5-43de-80C7-88CCE5AB269E.png)

```
if head == nil || head.Next == nil{
		return head
	}
	p := new(ListNode)
	q := p
	for head != nil && head.Next != nil{
		nextHead := head.Next.Next
		p.Next = head.Next
		head.Next = nil
		p.Next.Next = head
		p = p.Next.Next
		head = nextHead
	}
	if head != nil{
		p.Next = head
	}
	return q.Next
```
