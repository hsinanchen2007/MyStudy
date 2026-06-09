

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if not head:
            return None
        curnode=head
        ptr=head.next
        while ptr!=None:
            if curnode.val==ptr.val:
                ptr=ptr.next
            else:
                curnode.next=ptr
                curnode=curnode.next
                ptr=ptr.next
        curnode.next=None
        return head
```

![image.png](https://pic.leetcode-cn.com/8ed4cdb625910146a9260af89bf2fa040c6b5501832b53cd1ad63f908a5a3504-image.png)
