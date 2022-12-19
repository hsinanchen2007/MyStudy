### 解题思路
算法：查找单向链表，原地删除，删除所有节点一定要遍历到最后。考虑特殊情况删除头结点，head变化，可以增加头结点。
又叫哨兵节点，广泛应用于链表，如本题中伪头。
测试用例：
1.1个节点相等；
2.2个（多个）节点相等；
3.头部连续1个或者多个节点等于val；

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeElements(head *ListNode, val int) *ListNode {
	preHead := new(ListNode)
	preHead.Next = head
	for node := preHead; node != nil && node.Next != nil; {
		if node.Next.Val == val {
			node.Next = node.Next.Next
		}else {
			node = node.Next
		}
	}
	return preHead.Next
}
```