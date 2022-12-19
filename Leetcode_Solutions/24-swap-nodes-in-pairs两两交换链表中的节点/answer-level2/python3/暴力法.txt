直接从链表头开始交换节点，每交换一次指针后移两个单位。（之前题解都不会提交，代码直接跟文字混一起了。。。。。难受）


```python []
class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if head is None or head.next is None:
            return head
        l = ListNode(-1)
        q=l
        while head:
            if head.next is None:
                break
            p = head.next
            head.next = p.next
            p.next = head
            l.next = p
            l=l.next.next
            head = head.next
        return q.next
    
```

