### 解题思路
使用两个哑节点,一个存储小于x值的，一个存储大于x值的
最后合并两个哑节点

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func partition(head *ListNode, x int) *ListNode {
	resGt := &ListNode{}
	preGt := resGt
	resLt := &ListNode{}
	preLt := resLt
	for head != nil {
		node := head
		head = head.Next
		if node.Val < x {
			preLt.Next = node
			preLt = preLt.Next
		}else {
			preGt.Next = node
			preGt = preGt.Next
		}
	}
	preGt.Next = nil
	// 两个链表合并
	preLt.Next = resGt.Next
	return resLt.Next
}
```
### 执行结果
![image.png](https://pic.leetcode-cn.com/5687cfb3dfec5604c3cdb0b2e69124ca76888e8f72a0717c9c21ad16788a7888-image.png)
