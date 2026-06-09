### 解题思路
#### 保存链表头结点的方式
```
	oddHead, evenHead := &ListNode{}, &ListNode{}
	odd, even := oddHead, evenHead
```
### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func oddEvenList(head *ListNode) *ListNode {


	flag := 1

	for head != nil {
		if flag % 2 == 1{
			odd.Next = head
			odd = odd.Next
		} else {
			even.Next = head
			even = even.Next
		}
		flag++
		head = head.Next
	}

	even.Next = nil

	oddHead = oddHead.Next
	odd.Next = evenHead.Next

	return oddHead
}
```