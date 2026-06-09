### 解题思路
直接交换两个节点中的数值
![WechatIMG946.jpeg](https://pic.leetcode-cn.com/2144a671c08fd1dde9a56c133354911eec6fc040a8781daf4e84775c500c35f7-WechatIMG946.jpeg)

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
	if head == nil || head.Next == nil {
		return head
	}
    // pre的作用是保存原有数据，并在原有链表钱增加值为0的头结点
	pre := new(ListNode)
	pre.Next = head
    // 使用tmp记录当前需要操作的节点的前面一个节点
	tmp := pre

	for tmp.Next != nil && tmp.Next.Next != nil {
        
		start := tmp.Next
		end := tmp.Next.Next

		tmp.Next = end
		start.Next = end.Next
		end.Next = start
		tmp = start
	}

	return pre.Next
}
```