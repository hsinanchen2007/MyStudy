这个世界需要大佬的题解，也需要菜鸡的题解
三月二日打卡
```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
	if head==nil||head.Next==nil {
		return head
	}
	ht:=make([]*ListNode,2)
	rList(head,ht)
	return ht[0]
}
func rList(head *ListNode, ht []*ListNode) {
	if head.Next==nil {
		ht[0]=head
		ht[1]=head
		return
	}
	rList(head.Next,ht)
	ht[1].Next=head
	head.Next=nil
	ht[1]=head
}
```