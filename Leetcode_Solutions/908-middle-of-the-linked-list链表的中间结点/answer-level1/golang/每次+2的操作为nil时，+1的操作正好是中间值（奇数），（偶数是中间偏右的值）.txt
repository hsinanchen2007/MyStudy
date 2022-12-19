### 解题思路
#当每次+2的操作为nil时，+1的操作正好是中间值（奇数），（偶数是中间偏右的值）

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func middleNode(head *ListNode) *ListNode {
	slow, fast := head, head
	for fast != nil && fast.Next != nil {
		slow = slow.Next  //+1 每次加1的指针
		fast = fast.Next.Next //+2 每次加2的指针
		//当每次+2的操作为nil时，+1的操作正好是中间值（奇数），（偶数是中间偏右的值）
	}
	return slow
}
```