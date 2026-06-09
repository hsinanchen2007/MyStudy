方法很多，但为了性能还是一次循环比较好：
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
	if head == nil { //空链表直接返回
		return head
	}
	p := head.Next //指针指向下一个目标
	re := head     //将返回数据设置为第一个数据
	re.Next = nil  //断链使返回时的最后一个为nil
	for p != nil { //只要下一目标不为nil时循环
		q := p.Next //用临时指针指向下一个链表
		p.Next = re //将当前的下一个指向返回数据，相当于插入到re前面
		re = p      //保存返回数据
		p = q       //将临时指针赋值到下一个游动指针,为下一次循环做准备
	}
	return re
}