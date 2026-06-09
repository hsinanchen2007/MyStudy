### 解题思路
整个思路比较简单，就是注意临界条件：
1. 当反转的开始位置不是1，则返回结果肯定是头节点，可以临时保存下，后续完成反转直接返回
2. 当反转的开始位置是1时，则返回结果为最后的一个反转节点，也就是n处的节点
3. 注意反转时的边界节点，即m节点和m-1节点，m-1节点如果存在则可能需要更新next指针，m节点的next需要指向n处的下一个节点
4. 整个代码就直接通过序号index，顺序迭代，在范围内完成反转，在边界处处理相应的情况，最后在n处返回最终结果

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseBetween(head *ListNode, m int, n int) *ListNode {
    // 整个的返回值只可能是头节点或反转位置最后的节点（位置n处）
	
	// 临界条件，当head为空或m与n相等时，直接返回
	if head == nil || m == n {
		return head
	}

	// first记录头节点，当m>1时，最后会返回这个节点
	first := head
	// 索引序号
	index := 1

	// 记录反转的左边临界点，就是m的左边
	var leftPoint *ListNode
	// 记录开始反转的节点也就是m位置的节点
	var rightPoint *ListNode
	// 记录反转的临时节点
	var pre *ListNode

	for head != nil {
		switch {
		case index < m :
			// m之前的不反转，直接往前走
			if index == m - 1 {
				// 记录左临界点
				leftPoint = head
			}
			head = head.Next

		case index >= m && index <= n:
			if index == m {
				// 记录右节点
				rightPoint = head
			}
			// 开始反转
			next := head.Next
			head.Next = pre
			pre = head
			head = next

			if index == n {
				// 反转完成，补充临界节点的next指针
				if leftPoint != nil {
					leftPoint.Next = pre
				}

				if rightPoint != nil {
					rightPoint.Next = head
				}

				switch {
				case m > 1:
					return first
				default:
					return pre
				}
			}
		}
		index ++
	}

	return head
}
```

整个时间复杂度为O(n)