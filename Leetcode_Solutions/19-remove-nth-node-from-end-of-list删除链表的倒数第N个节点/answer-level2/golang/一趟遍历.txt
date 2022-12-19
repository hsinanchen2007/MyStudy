### 解题思路
1. 在head前面增加一个哑节点
2. 制定两个指针， 一个指针指向head。 一个指针从哑节点开始
### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
	offset := 0
	h := head
	pre := &ListNode{Next:head}
	preItor := pre
	for h != nil {
		h = h.Next
		if offset < n  {
			offset += 1
			continue
		}
		preItor = preItor.Next
	}
	deleteNode := preItor.Next
	preItor.Next= deleteNode.Next
	deleteNode.Next = nil
	return pre.Next
}
```
### 执行结果
![image.png](https://pic.leetcode-cn.com/010998a4a19945e6462175fdecad27e370bebb05454643ee6f6d84aa2e1384ca-image.png)
