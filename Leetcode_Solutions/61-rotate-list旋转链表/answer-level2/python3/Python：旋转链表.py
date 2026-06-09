### 解题思路
循环列表
时间复杂度O(n+m)
空间复杂度O(n)
因为是Python做类，所以这个多一个变量，就相当于空间多一倍

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if not head:return head
        num=1
        ptr=head
        while ptr.next:
            ptr=ptr.next
            num+=1
        ptr.next=head
        count=num-k%num
        while count>0:
            ptr=head
            head=head.next
            count-=1
        ptr.next=None
        return head
```