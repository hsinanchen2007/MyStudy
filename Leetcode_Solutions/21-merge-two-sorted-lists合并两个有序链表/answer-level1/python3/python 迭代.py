### 解题思路
逐个比较加入链表就行

### 代码
```
```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        head=dummy=ListNode(-1)
        while l1 and l2:
            if l1.val<l2.val:
                dummy.next=l1
                l1=l1.next
            else:
                dummy.next=l2
                l2=l2.next
            dummy=dummy.next
        dummy.next=l1 if l1 else l2
        return head.next
        
```



```

