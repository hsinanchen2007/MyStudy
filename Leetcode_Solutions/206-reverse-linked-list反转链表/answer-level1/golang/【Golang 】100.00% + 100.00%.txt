### 解题思路

用两个指针，一个指向前一个节点`prev`，另一个指向当前节点`cur`。
初始化时，
1. `prev`为空节点。因为反转完成后，末节点是指向NULL的。
2. `cur`指向头节点。

反转的过程为，当前节点的`Next`指向`prev`，当前节点`cur`走到下一个节点`cur.Next`，前一个节点`prev`同样往前走一步，指向`cur`。
如果当前节点`cur`为空，则说明`cur`已经走到原链表的尾指针的Next。
此时返回`prev`，便是新链表的头节点。

### 代码

```golang

func reverseList(head *ListNode) *ListNode {
    var prev *ListNode
	cur := head

	for cur != nil {
		prev, cur, cur.Next = cur, cur.Next, prev
	}

	return prev
}

```