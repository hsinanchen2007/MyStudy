### 解题思路
使用两个指针，一个快指针，每次走两步，一个慢指针，每次走一步。当快指针走到尾部时，慢指针在链表中间，此时将链表后半部分反转。最后将头尾依次链接即可。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if not head or not head.next or not head.next.next:
            return head
        slowptr=head
        fastptr=head
        while fastptr and fastptr.next:
            slowptr=slowptr.next
            fastptr=fastptr.next.next
        ptr=slowptr.next
        slowptr.next=None
        while ptr:
            r=ptr.next
            ptr.next=slowptr
            slowptr=ptr
            ptr=r
        ptr=head
        while slowptr.next:
            p=ptr.next
            q=slowptr.next
            ptr.next=slowptr
            slowptr.next=p
            ptr=p
            slowptr=q
```

![image.png](https://pic.leetcode-cn.com/b7e0faffea601c22d0e290533c07d8644f31e2737cf1fbb3f5f3b57cbec4ecc9-image.png)
