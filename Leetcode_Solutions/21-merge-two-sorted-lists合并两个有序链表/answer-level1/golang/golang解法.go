```
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	var node *ListNode
	var lastNode *ListNode
	_l1 := l1
	_l2 := l2
	if _l1 == nil {
		return _l2
	}
	if _l2 == nil {
		return _l1
	}
	for {
		if _l1 == nil {
			lastNode.Next = _l2
			break
		}
		if _l2 == nil {
			lastNode.Next = _l1
			break
		}
		if _l1.Val <= _l2.Val {
			if node == nil {
				node = &ListNode{
					Val: _l1.Val}
				lastNode = node
			} else {
				tmp := &ListNode{
					Val: _l1.Val,
				}
				lastNode.Next = tmp
				lastNode = tmp
			}
			_l1 = _l1.Next
		} else {
			if node == nil {
				node = &ListNode{
					Val: _l2.Val}
				lastNode = node
			} else {
				tmp := &ListNode{
					Val: _l2.Val,
				}
				lastNode.Next = tmp
				lastNode = tmp
			}
			_l2 = _l2.Next
		}
	}
	return node
}
```
