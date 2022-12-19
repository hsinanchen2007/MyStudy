### 解题思路
两次遍历构造平移后的正确顺序resultList，再递归创造平移后的链表

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func rotateRight(head *ListNode, k int) *ListNode {
	tempList := make([]int, 0)
	for ; head != nil; head = head.Next {
		tempList = append(tempList, head.Val)
	}
	resultList := make([]int, len(tempList))
	for i, v := range tempList {
		if i + k < len(tempList) { // 如果平移后没有超出数组长度
			resultList[i+k] = v
		} else { // 如果超出数组长度
			index := (i + k) % len(tempList)
			resultList[index] = v
		}
	}
	return buildList(resultList)
}

func buildList(list []int) *ListNode {
	if len(list) == 0 {
		return nil
	} else {
		node := ListNode{
			Val: list[0],
		}
		node.Next = buildList(list[1:])
		return &node
	}
}
```