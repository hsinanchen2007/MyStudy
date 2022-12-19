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
func deleteDuplicates(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
	posHeadMap := make(map[int]*ListNode) // 存储某个值第一次出现的节点
	values := make([]int, 0) // 按顺序存储从未出现过的元素值
	var preNotDupNode *ListNode // 到目前为止最后一个从未出现过的节点
	for head != nil {
		if _, ok := posHeadMap[head.Val]; ok { // 已经出现过，更新values,preNotDupNode
			if len(values) > 0 {
				if values[len(values)-1] == head.Val {
					values = values[:len(values)-1]
				}
			}
			if len(values) == 0 {
				preNotDupNode = nil
			} else {
				preNotDupNode = posHeadMap[values[len(values)-1]]
				preNotDupNode.Next = nil
			}
		} else {
			if preNotDupNode != nil {
				preNotDupNode.Next = head
			}
			preNotDupNode = head // 更新preNotDupNode
			posHeadMap[head.Val] = head
			values = append(values, head.Val)
		}
		head = head.Next
	}
	if len(values) == 0 {
		return nil
	}
	return posHeadMap[values[0]]
}
```