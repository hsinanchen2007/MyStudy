### 解题思路

执行用时 :0 ms, 在所有 Go 提交中击败了100.00% 的用户
内存消耗 :2.1 MB, 在所有 Go 提交中击败了100.00%的用户

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
	root := &ListNode{
		Val:  0,
		Next: head,
	}
	cur := root
	for cur.Next != nil && cur.Next.Next != nil {
		// 光标指向2,2指向1，1指向3，光标移到3前
		cur.Next, cur.Next.Next, cur.Next.Next.Next, cur =
			cur.Next.Next, cur.Next.Next.Next, cur.Next, cur.Next
	}
	return root.Next
}
```