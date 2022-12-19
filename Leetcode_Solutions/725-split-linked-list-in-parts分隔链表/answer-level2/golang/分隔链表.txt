### 解题思路
先平均分配,有余再均分给开头几个大兄弟.

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func splitListToParts(root *ListNode, k int) []*ListNode {
	n := 0
	p := root
	for p != nil {
		n++
		p = p.Next
	}
	ans := make([]*ListNode, k)
	p = root
	if n <= k {
		i := 0
		for p != nil {
			ans[i] = p
			p = p.Next
			ans[i].Next = nil
			i++
		}
		return ans
	}

	size := n / k
	left := n - size*k
	for i := 0; i < k; i++ {
		ans[i] = p
		for j := 1; j < size; j++ {
			p = p.Next
		}
		if left > 0 {
			left--
			p = p.Next
		}
		next := p.Next
		p.Next = nil
		p = next
	}
	return ans
}

```