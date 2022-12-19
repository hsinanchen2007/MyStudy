### 解题思路
单链表中每个节点的地址都存储在其前驱结点的指针域中。
在遍历链表时，修改当前节点指针域的指向，使其指向前驱节点，因此需要一个变量可以找到前驱节点，此变量为 prev。
另外，还需要记录下当年节点的原始后继节点，不然无法继续遍历了，此变量为 next。
还需要一个变量记录当前遍历到的节点，此变量为 curr。

画个图很容易看懂代码，就不画了。

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
    if head == nil || head.Next == nil { // 提前发现异常
		return head
	}
	var prev, next *ListNode
	curr := head
	for curr != nil {
		next = curr.Next // 调整 next
		curr.Next = prev // 调整当前节点的指针域指向
		prev = curr // 更新 prev
		curr = next // 更新 curr，接着往下遍历
	}
    // 遍历完成后，curr == next == nil，prev 指向反转链表的 head 
	return prev
}
```