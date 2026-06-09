### 解题思路
奥利给！干就完了！

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reversePrint(head *ListNode) []int {
	result := []int{}
	for head != nil {
		result = append(result, head.Val)
		head = head.Next

	}
	length := len(result)
	// 倒置
	for i := 0; i < length/2; i++ {
		result[i],result[length-1-i] = result[length-1-i],result[i]
	}
	return result
}
```