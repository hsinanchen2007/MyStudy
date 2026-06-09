## 1.Java实现
```java
class Solution {
    public ListNode removeZeroSumSublists(ListNode head) {
        ListNode ahead = new ListNode(-1);
        ListNode h = ahead;
        h.next = head;
        ListNode q = h.next;
        while (h.next != null) {
            int sum = 0;
            while (q != null) {
                sum += q.val;
                if (sum == 0) {
                    break;
                }
                q = q.next;
            }
            if (sum == 0) {
                // h.next至q之间的的连续子链表和等于0，那么删除这段子链表，亦即将h.next和q指针都指向q.next，进入下一层循环
                q = q.next;
                h.next = q;
            } else {
                // h.next开头的所有连续子链表累加和都不等于0，那么h.next节点应该保留，并继续从h.next.next开始检测
                h = h.next;
                q = h.next;
            }
        }
        return ahead.next;
    }
}
```

## 2. Go实现
```go
func removeZeroSumSublists(head *ListNode) *ListNode {
	p := &ListNode{}
	p.Next = head
	h := p
	t := h.Next
	for h.Next != nil {
		sum := 0
		for t != nil {
			sum += t.Val
			if sum == 0 {
				break
			}
			t = t.Next
		}
		if sum == 0 {
			t = t.Next
			h.Next = t
		} else {
			h = h.Next
			t = h.Next
		}
	}

	return p.Next
}
```

