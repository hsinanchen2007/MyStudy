```go
/**
 * 方法一：复制到数组，双指针前后遍历 . 32ms
 */
func isPalindrome(head *ListNode) bool {
	if head == nil {
		return true // 按照官方的测试案例，空链表是回文链表
	}

	hashMap := []int{}
	for head != nil {
		hashMap = hashMap.append(head.Val)
		head = head.Next
	}

	left, right := 0, len(hashMap)-1
	for left <= right {
		if hashMap[left] != hashMap[right] {
			return false
		}
		left++
		right--
	}
	return true
}
```

```go
/**
 * 方法二：快慢指针 . 12ms
 * 通过快慢指针找到中点，反转后半部分链表且进行比较
 */
func isPalindrome(head *ListNode) bool {
	if head == nil {
		return true
	}
	// 找出中点，快指针到了链表结尾，慢指针也就到了链表中点
	mid := findMid(head)
	// 翻转后半部分链表
	rev := reverse(mid)
	// 比对前后链表
	for rev != nil && head != nil {
		if head.Val != rev.Val {
			return false
		}
		rev, head = rev.Next, head.Next
	}
	return true
}

func findMid(head *ListNode) *ListNode {
	slow, fast := head, head
	for fast != nil && fast.Next != nil {
		slow, fast = slow.Next, fast.Next.Next
	}
	return slow
}

func reverse(head *ListNode) *ListNode {
    // 经过遍历，后半部分链表会变成一个头节点为 prev，最后为 nil 的链表
	var prev, curr *ListNode = nil, head
	for curr != nil {
		prev, curr, curr.Next = curr, curr.Next, prev
	}
	return prev
}
```