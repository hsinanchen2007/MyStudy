### 解题思路

- 输入: `1->2->3->4->5->NULL`
- 反转`nil<-1<-2<-3<-4<-5`


### 代码
- 递归实现

```golang

func reverseList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	end := reverseList(head.Next)

	next := head.Next
	head.Next = nil
	next.Next = head

	return end
}
```


- 迭代实现
```go
func reverseList(head *ListNode) *ListNode {

	var (
		current *ListNode
		upper   *ListNode
	)
	current = head
	for current != nil {
		next := current.Next
		current.Next = upper

		upper = current
		current = next

	}

	return upper
}
```
