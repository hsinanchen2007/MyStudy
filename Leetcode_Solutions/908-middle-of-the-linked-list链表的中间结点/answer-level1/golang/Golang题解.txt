### 解题思路
此处撰写解题思路

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
    // 先计算长度
	node := &ListNode{
		Val:  0,
		Next: head,
	}
	length := 0
	for node.Next != nil {
		node = node.Next
		length++
	}

	// 计算中间元素
	var startIndex int = length / 2
	fmt.Println("startIndex:", startIndex)
	if startIndex == 0 {
		return head
	}
	counter := 0
	for head.Next != nil {
		head = head.Next
		counter++
		if startIndex == counter {
			return head
		}
	}
	return nil
}
```