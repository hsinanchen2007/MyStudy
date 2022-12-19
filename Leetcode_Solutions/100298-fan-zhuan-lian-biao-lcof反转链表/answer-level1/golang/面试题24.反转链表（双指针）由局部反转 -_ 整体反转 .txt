### 解题思路
双指针(pre + cur) 
注意临界处细节

### 知识点：双指针（局部反转 -> 整体反转)

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
    	if head == nil {
		return nil
	}

	cur, pre := head.Next, head
	head.Next = nil
	for cur != nil {
		// 局部反转
		temp := cur.Next
		cur.Next = pre
		pre = cur
		cur = temp
	}
	
	return pre
}
```