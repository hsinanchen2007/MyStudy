### 解题思路
此处撰写解题思路

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func swapPairs(head *ListNode) *ListNode {
	if head == nil || head.Next == nil{
		return head
	}
	var preSwap *ListNode
	var pre *ListNode
	var root *ListNode
	count := -1
	for head != nil {
		count += 1
		if count%2 == 0 {
			pre = head
			if head.Next == nil && preSwap != nil {
			    preSwap.Next = head
			}
			head = head.Next
		} else {
			if count == 1 {
				root = head
			}
			next := head.Next
			head.Next = pre
			pre.Next = nil
			//fmt.Println(preSwap.Val)
			if preSwap != nil {
				preSwap.Next = head
			}
			preSwap = pre
			head = next
		}
	}
	return root
}
```