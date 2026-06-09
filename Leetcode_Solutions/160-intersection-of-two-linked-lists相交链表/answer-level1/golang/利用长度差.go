### 解题思路
长链表的指针先走几步,然后同时走.相遇点就是相交点.

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getIntersectionNode(headA, headB *ListNode) *ListNode {
	an := 0
	p := headA
	for p != nil {
		an++
		p = p.Next
	}
	bn := 0
	p = headB
	for p != nil {
		bn++
		p = p.Next
	}
	pa := headA
	pb := headB
	if an > bn {
		n := an - bn
		for n > 0 {
			pa = pa.Next
			n--
		}
	} else {
		n:=bn - an
		for n > 0{
			pb = pb.Next
			n--
		}
	}
	for pa != pb {
		pa = pa.Next
		pb = pb.Next
	}
	return pa
}

```