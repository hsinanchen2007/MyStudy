### 解题思路
1、声明一个二维切片，每两个是一组。遍历链表，填充到切片中
2、遍历切片，重新生成一个链表

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
    t, l := head, 0
	for t != nil {
		l++
		t = t.Next
	}
	if l == 0 {
		return nil
	}
	if l == 1 {
		return head
	}
	var slice [][2]*ListNode
	tmp := [2]*ListNode{nil, nil}
	var length int
	if l % 2 == 0 {
		length = l / 2
	} else {
		length = (l / 2) + 1
	}
	for i := 0; i < length; i++ {
		for j := 0; j < 2; j++ {
			tmp[j] = head
			if head.Next == nil {
				break
			}
			head = head.Next
		}
		slice = append(slice, tmp)
		tmp = [2]*ListNode{nil, nil}
	}
	dummy := &ListNode{
		Val:  0,
		Next: nil,
	}
	ret := dummy
	for _, v := range slice {
		if v[1] != nil {
			dummy.Next = v[1]
			dummy = dummy.Next
		}
		dummy.Next = v[0]
		dummy = dummy.Next
	}
	if dummy != nil {
		dummy.Next = nil
	}
	return ret.Next
}
```