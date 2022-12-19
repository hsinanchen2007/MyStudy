### 解题思路
先构造奇偶链表,在首尾相接.

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
	oddHead, evenHead := &ListNode{}, &ListNode{}
	odd, even := oddHead, evenHead
	
	i := 1
	p := head
	for p!= nil{
		if i%2 == 1 {
			odd.Next = p
			odd = odd.Next
		}else {
			even.Next = p
			even = even.Next
		}
		p = p.Next
		i++
	}
	even.Next = nil
	odd.Next = evenHead.Next
	return oddHead.Next
}
```