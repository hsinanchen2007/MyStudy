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

func isPalindrome(head *ListNode) bool {

	if head == nil || head.Next == nil {
		return true
	}

	cnt := 0
	cur := head
	for cur != nil {
		cnt++
		cur = cur.Next
	}

	vhead := &ListNode{-1, head}	
    slow, fast := vhead, vhead
	for fast.Next != nil && fast.Next.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
	}

    var head2 *ListNode
	if cnt%2 == 0 {
		head2 = slow.Next
		slow.Next = nil
	} else {
		head2 = slow.Next.Next
		slow.Next = nil
	}

	h2 := reverseLinkedList(head2)
	cur = vhead.Next
	for cur != nil && h2 != nil {
		if cur.Val != h2.Val {
			return false
		}
		cur = cur.Next
		h2 = h2.Next
	}

	return true
}

func reverseLinkedList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	virtualHead := &ListNode{-1, nil}

    cur := head

	for cur != nil {
		tmp := cur.Next
		cur.Next = virtualHead.Next
		virtualHead.Next = cur
		cur = tmp
	}

	return virtualHead.Next
}

```