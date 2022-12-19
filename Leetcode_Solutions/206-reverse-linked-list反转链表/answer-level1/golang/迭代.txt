### 解题思路

标准官方题解思路,注意go初始化变量

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
var res *ListNode
	cur := head
	for ;cur!=nil ; {
		tmp := cur.Next
		cur.Next = res
		res = cur
		cur = tmp
	}
	return res
}
```