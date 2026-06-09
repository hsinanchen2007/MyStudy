### 解题思路
模拟一个正常人的解题思路，不考虑递归的方式，毕竟也没谁数学考试时，用递归，哈哈；不过递归确实更省事一些。这里就只是纯粹的迭代两条链表。两数在相加的过程中，可能产生进位，特别是在最后一个节点时。

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    resultNode := new(ListNode)
	endNode := new(ListNode)
	exitForLoop := false
	lastEndNode := resultNode
	for {
		// 每次循环都产生一个结果节点
		positionNode := new(ListNode)
		if l1 != nil && l2 != nil {
			// 位数均存在，才做加法操作嘛
			if l1.Val + l2.Val > 9 {
				// 考虑进位操作，和余数问题，进位的值可以直接加到下一节点
				remainValue := (l1.Val + l2.Val) % 10
				positionNode.Val = remainValue
				if l1.Next != nil {
					l1.Next.Val += 1
				} else if l2.Next != nil {
					l2.Next.Val += 1
				} else {
					// 如果没法加到下一节点，就新生成一个最终节点
					endNode.Val = 1
				}
			} else {
				remainValue := l1.Val + l2.Val
				positionNode.Val = remainValue
			}
			// 前往下一节点
			if l1.Next != nil && l2.Next != nil {
				l1 = l1.Next
				l2 = l2.Next
			} else if l1.Next != nil {
				l1 = l1.Next
				l2 = nil
			} else if l2.Next != nil {
				l2 = l2.Next
				l1 = nil
			} else {
				l1 = nil
				l2 = nil
				exitForLoop = true
				//break
			}
		} else if l1 != nil {
			// l1长度 > l2长度，那就直接取l1的下一节点加上可能的
			if l1.Val > 9 {
				remainValue := l1.Val % 10
				positionNode.Val = remainValue
				if l1.Next != nil {
					l1.Next.Val += 1
				} else {
					// 如果没法加到下一节点，就新生成一个最终节点
					endNode.Val = 1
				}
			} else {
				positionNode.Val = l1.Val
			}
			if l1.Next != nil {
				l1 = l1.Next
			} else {
				l1 = nil
				exitForLoop = true
			}
		} else if l2 != nil {
			// l1长度 < l2长度，那就直接取l1的下一节点加上可能的
			if l2.Val > 9 {
				remainValue := l2.Val % 10
				positionNode.Val = remainValue
				if l2.Next != nil {
					l2.Next.Val += 1
				} else {
					// 如果没法加到下一节点，就新生成一个最终节点
					endNode.Val = 1
				}
			} else {
				positionNode.Val = l2.Val
			}
			if l2.Next != nil {
				l2 = l2.Next
			} else {
				l2 = nil
				exitForLoop = true
			}
		} else {
			exitForLoop = true
		}
		lastEndNode.Next = positionNode
		lastEndNode = lastEndNode.Next
		if exitForLoop {
			// 两者长度相等
			break
		}
	}
	if endNode.Val != 0 {
		lastEndNode.Next = endNode
	}
	return resultNode.Next
}
```