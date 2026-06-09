
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:

        while head and head.val==val:
            head=head.next
        if not head:
            return head
        ptr=head.next
        cur=head
        while ptr!=None:
            if ptr.val==val:
                ptr=ptr.next
            else:
                cur.next=ptr
                cur=ptr
                ptr=ptr.next
        cur.next=None
        return head
```

![image.png](https://pic.leetcode-cn.com/f4085bb7dcd70852834a46f31501b60948bd10c04f407d55ea4f1d258e94c96e-image.png)
