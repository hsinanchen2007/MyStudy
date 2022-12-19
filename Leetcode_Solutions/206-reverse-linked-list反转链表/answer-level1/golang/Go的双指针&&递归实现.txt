### 参考链接
https://leetcode-cn.com/problems/reverse-linked-list/solution/dong-hua-yan-shi-206-fan-zhuan-lian-biao-by-user74/

### 双指针迭代
1. 用两个指针pre和cur，从左->右遍历链表，同时将next的指针指向前面一个元素。T(n)=O(n).

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
	var pre *ListNode = nil //pre指针先指向一个空。
	cur :=  head
	for cur != nil {
		cur.Next, pre, cur = pre, cur, cur.Next
	}
	return pre //返回pre指针，pre为翻转后的链表的头节点。
}
```

### 递归
1. 这题有个很骚气的递归解法，递归解法很不好理解，这里最好配合代码和动画一起理解。
递归的两个条件：

终止条件是当前节点或者下一个节点==null
在函数内部，改变节点的指向，也就是 head 的下一个节点指向 head 递归函数那句
head.next.next = head
很不好理解，其实就是 head 的下一个节点指向head。
递归函数中每次返回的 newHead始终是原链表的最后一个节点，也就是翻转后的链表的头指针。在递归函数内部，改变的是当前节点的指向。

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil{
		return head
	}

	newHead := reverseList(head.Next) //自始至终返回的是链表的最后一个节点
	// 1->2->3->4->  5
	// 此时head指向4，令5.Next=4
	head.Next.Next = head//未翻转链表的最后一个节点的Next->未翻转链表的最后一个节点
	// 防止循环链表的产生，也防止了对新链表的最后一个节点做处理
	head.Next = nil

	//每层递归函数都返回newHead，也就是原链表的最后一个节点
	return newHead
}
```