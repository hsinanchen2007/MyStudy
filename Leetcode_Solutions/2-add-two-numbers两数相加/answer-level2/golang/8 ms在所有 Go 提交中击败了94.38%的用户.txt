### 解题思路
此处撰写解题思路

执行用时 :
8 ms在所有 Go 提交中击败了94.38%的用户
内存消耗 :5 MB, 在所有 Go 提交中击败了86.64%的用户

主要在于考虑 没有进位的时候，可以把后续的直接接过来

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
  
	if l1 == nil {
		return l2
	}

	if l2 == nil {
		return l1
	}

	var l3, l3Pre, tmp *ListNode
	t := 0

	l3 = &ListNode{
		Val: l1.Val + l2.Val,
	}

	if l3.Val >= 10 {
		l3.Val = l3.Val - 10
		t = 1
	}

	l3Pre = l3

	for {

		if l1 != nil {
			l1 = l1.Next
		}

		if l2 != nil {
			l2 = l2.Next
		}

		if l1 == nil && l2 == nil {
			if t == 0 {
				return l3
			}

			l3Pre.Next = &ListNode{
				Val: 1,
			}

			return l3
		}
		// 优化处理，如果没有了进位，某个链接已经到头了，就可以把另外一个链表剩余的直接接过来
        if t == 0 {
			if l1 == nil {
				l3Pre.Next = l2
				return l3
			}

			if l2 == nil {
				l3Pre.Next = l1
				return l3
			}
		}

		tmp = &ListNode{}
		if l1 != nil {
			tmp.Val = tmp.Val + l1.Val
		}

		if l2 != nil {
			tmp.Val = tmp.Val + l2.Val
		}

		tmp.Val = tmp.Val + t
		if tmp.Val >= 10 {
			tmp.Val = tmp.Val - 10
			t = 1
		} else {
			t = 0
		}

		l3Pre.Next = tmp
		l3Pre = tmp

	}

	return l3
}
```