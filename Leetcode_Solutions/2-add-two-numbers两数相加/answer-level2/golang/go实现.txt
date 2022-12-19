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
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    fakeHead := new(ListNode)
	carry := 0
	cur := fakeHead

	for l1 != nil || l2  != nil || carry != 0 {

		if l1 != nil {
			carry += l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			carry    += l2.Val
			l2 = l2.Next
		}

		tmp := new(ListNode)
		tmp.Val = carry  %10
		carry = carry /10
		cur.Next = tmp
		cur = tmp

	}
	return fakeHead.Next

}
```