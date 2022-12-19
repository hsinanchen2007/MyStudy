### 解题思路
一次遍历

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
	p := head
	for p!=nil {
		val := p.Val
		for p.Next!=nil && p.Next.Val ==  val{
			p.Next = p.Next.Next
		}
		p = p.Next
	}
	return head
}
```