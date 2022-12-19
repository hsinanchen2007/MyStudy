

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        head=ListNode(0)
        ptr=head
        if not l1:
            return l2
        elif not l2:
            return l1
        while l1!=None and l2!=None:
            if l1.val<=l2.val:
                ptr.next=l1
                ptr=ptr.next
                l1=l1.next
            else:
                ptr.next=l2
                ptr=ptr.next
                l2=l2.next
        if l1!=None:
            ptr.next=l1
        else:
            ptr.next=l2
        return head.next
```

![image.png](https://pic.leetcode-cn.com/a52c049bebefdfbc5ae2cecb7eaf0fc94f6823fe458b384c9029a7dfb59a6a64-image.png)
