```java
class Solution {
    fun reverseBetween(head: ListNode?, m: Int, n: Int): ListNode? {
        val dummy = ListNode(0)
        dummy.next= head
        var pre = dummy
        for (index in 0 until m - 1) {
            pre = pre.next!!
        }
        var start = pre.next
        var end :ListNode? = start
        for (index in 0 until n - m) {
            end = end!!.next
        }
        var headOfRemained :ListNode? = end!!.next
        end.next = null
        pre.next = reverse(start!!)
        start.next = headOfRemained
        return dummy.next
    }

    private fun reverse(head: ListNode): ListNode? {
        var pre :ListNode? = null
        var curr :ListNode? = head
        while (curr != null) {
            var next = curr.next
            curr.next = pre
            pre = curr
            curr = next
        }
        return pre
    }
}
```

```go
func reverseBetween(head *ListNode, m int, n int) *ListNode {
	dummy := &ListNode{
		Val:  0,
		Next: head,
	}
	pre := dummy
	for i := 0; i < m - 1; i++ {
		pre = pre.Next
	}
	start := pre.Next
	end := start
	for i := 0; i < n - m; i++ {
		end = end.Next
	}
	headOfRemained := end.Next
	end.Next = nil
	pre.Next = reverse(start)
	start.Next = headOfRemained
	return dummy.Next
}

func reverse(head *ListNode) *ListNode {
	var pre *ListNode = nil
	curr := head
	for curr != nil {
		next := curr.Next
		curr.Next = pre
		pre = curr
		curr = next
	}
	return pre
}
```