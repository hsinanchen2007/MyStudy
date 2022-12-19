### 解题思路
使用集合.

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func numComponents(head *ListNode, G []int) int {
	set := make(map[int]int)
	for _, v := range G {
		set[v] = 1
	}
	num, p := 0, head
	for p != nil {
		b := false
		for p != nil {
			if _, ok := set[p.Val]; ok {
				b = true
			} else {
				break
			}
			p = p.Next
		}
		if b {
			num++
		}
		for p != nil {
			if _, ok := set[p.Val]; ok {
				break
			}
			p = p.Next
		}
	}
	return num
}

```