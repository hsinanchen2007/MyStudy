

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
    res := &ListNode{} // 哑节点
	pre := res
	var (
		node1 *ListNode
		node2 *ListNode
	)
	for head != nil {
		head, node1 = head.Next, head
		if head == nil {
			pre.Next = node1
			pre = pre.Next
			break
		}
		head, node2 = head.Next, head
		pre.Next = node2
		pre = pre.Next
		pre.Next = node1
		pre = pre.Next
	}
	pre.Next = nil
	return res.Next
}
```

###执行结果
![image.png](https://pic.leetcode-cn.com/500762f978c39c3528f52f0977c0650d4330c04a01f693fb43bf57cdc9857f5f-image.png)
