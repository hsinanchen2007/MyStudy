语言：Python3
效果：O(n) 56ms 13.7MB
代码
```python []
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        result = ListNode(0)
        temp = result
        while l1 and l2:
            val1 = l1.val
            val2 = l2.val
            # 根据大小决定移动哪个链表
            if val1 <= val2:
                val = val1
                l1 = l1.next
            else:
                val = val2
                l2 = l2.next
            temp.next = ListNode(val)
            temp = temp.next
        # 将剩余的链表直接接上
        temp.next = l1 if l1 else l2
        return result.next
```
