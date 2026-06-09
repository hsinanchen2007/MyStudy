### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
    if head==nil||head.Next==nil{
		return head
	}else{
		var p1,p2 = &*head,&ListNode{}
		for p1!=nil{
			p2 =p1.Next

			for p2!=nil{
				if p1.Val == p2.Val{
					p1.Next = p2.Next
				}
				p2 = p2.Next
			}
			p1 = p1.Next
		}
		return head
	}
}
```