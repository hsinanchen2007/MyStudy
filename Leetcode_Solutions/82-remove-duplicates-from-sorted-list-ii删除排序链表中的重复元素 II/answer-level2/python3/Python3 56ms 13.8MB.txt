
```python []
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if head == None or head.next == None: return head
        temp = ListNode(head.val - 1)
        temp.next = head
        slow, fast = temp, head
        while fast:
            # 如果重复无限重指向
            while fast.next and fast.val == fast.next.val:
                fast = fast.next
            if slow.next == fast:
                slow = slow.next
            else:
                slow.next = fast.next
            fast = fast.next
        return temp.next
```

