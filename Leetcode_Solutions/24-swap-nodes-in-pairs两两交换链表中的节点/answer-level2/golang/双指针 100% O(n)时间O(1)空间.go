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

	//指针移动step=2
	ps := head
	pf := ps
	for ;ps != nil && ps.Next != nil ;{
		pf = ps.Next
		tmp := ps.Val
		ps.Val = pf.Val
		pf.Val = tmp
		ps = pf.Next

	}

	return  head
}
```