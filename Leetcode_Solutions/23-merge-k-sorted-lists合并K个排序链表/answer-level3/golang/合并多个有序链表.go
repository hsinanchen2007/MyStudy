每次遍历所有链表，找到头结点最小值，放到返回的链表中，同时把找到的链表头结点删除，当某一链表遍历完成时，移出链表数组，直到数组中链表全部遍历完
```
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeKLists(lists []*ListNode) *ListNode {
    if len(lists) == 0 {
        return nil
    }
    tempList := []*ListNode{}
	for _, v := range lists {
		if v != nil {
			tempList = append(tempList, v)
		}
	}
	lists = tempList
    var head *ListNode = nil
	var node *ListNode = nil
	for len(lists) > 0 {
		min := lists[0].Val
		minIndex := 0
		for i:=1;i<len(lists);i++ {
			if lists[i].Val < min {
				min = lists[i].Val
				minIndex = i
			}
		}
		tempNode := &ListNode{Val:min}
		if node == nil {
			node = tempNode
			head = node
		}else {
			node.Next = tempNode
			node = node.Next
		}
		minNode := lists[minIndex]
		if minNode.Next == nil {
			if minIndex == len(lists)-1{
				lists = lists[:minIndex]
			}else {
				lists = append(lists[:minIndex], lists[minIndex+1:]...)
			}
		}else {
			minNode.Val = minNode.Next.Val
			n := minNode.Next.Next
			minNode.Next.Next = nil
			minNode.Next = n
		}
	}
	return head
}
```
