### 解题思路
方法比较笨，每次找到倒数第二个节点和最后一个节点，把最后一个节点的next指向倒数第二个节点，把倒数第二个节点的next置空，这样原倒数第二个节点就成了原链表最后一个节点，以此迭代
需要注意的是头节点为空和仅有一个节点的情况
### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
  	var p *ListNode
	var newhead *ListNode
	if head!=nil&&head.Next!=nil {
		for p = head; p.Next != nil; p = p.Next {
		}
		newhead = p
		for p != head {
			for p = head; p.Next.Next != nil; p = p.Next {
			}
			tmp := p.Next
			p.Next = nil
			tmp.Next = p
		}
		return newhead
	}else{
		return head
	}
}
```