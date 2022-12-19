### 解题思路
> fast以及fast.Next相同则删除slow到fast.Next.Next{有可能是多个相同，则需要找到最后一个相同值，应为该位置是slow的位置}之间元素

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
	if head == nil || head.Next == nil {
		return head
	}
	//var rwLocker sync.RWMutex
	dummy := &ListNode{head.Val - 1, head}
	slow := dummy
	fast := dummy.Next

	//删除快慢指针之间相同的元素
	for fast != nil && fast.Next != nil && fast.Next.Next != nil {
		//slow fast 之间元素不同
		if fast.Val != fast.Next.Val {
			slow = fast
			fast = fast.Next
			//删除重复元素
		} else {
			for fast.Next != nil && fast.Next.Next != nil && fast.Next.Val == fast.Next.Next.Val {

				fast.Next = fast.Next.Next
			}
			slow.Next = fast.Next.Next //删除重复元素
			fast = fast.Next.Next
		}
	}

	////slow元素之后的全部元素都相同
	if fast != nil && fast.Next != nil && fast.Val == fast.Next.Val {
		slow.Next = nil
	}
	return dummy.Next


}
```