关键记住是翻转前的一个指针，和翻转之后末尾指针即可
```go
	if head == nil || m == n {
		return head
	}
	newHead := head
	p := head
	q := head.Next
	var firstEnd *ListNode
	var secondBegin *ListNode
	cnt := 0
	for q != nil {
		cnt++
		if cnt < m {
			firstEnd = p
			p = p.Next
			q = q.Next
		} else if cnt >= m && cnt < n {
			if cnt == m {
				p.Next = nil
				secondBegin = p
			}
			if cnt == n-1 {
				secondBegin.Next = q.Next
			}
			tmp := q.Next
			q.Next = p
			p = q
			q = tmp
			if firstEnd != nil {
				firstEnd.Next = p
			} else {
				newHead = p
			}
		} else {
			break
		}
	}
	return newHead
```