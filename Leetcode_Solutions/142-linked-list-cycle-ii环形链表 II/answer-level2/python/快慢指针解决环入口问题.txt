### 解题思路
采用双指针算法中的快慢指针进行求解：
  快慢指针：第一：fast走到链表末，返回null；第二：fast=slow，两指针第一次相遇，slow指针同时从相遇的位置和最开始的位置出发，相遇的位置即为环入口。

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        fast,slow=head,head 
        while fast !=None:
            fast=fast.next
            if fast==None:
                break
            fast=fast.next
            slow=slow.next 
            if slow==fast:
                break
        if fast==None:
            return None
        P1,P2=slow,head 
        while P1!=P2:
            P1=P1.next
            P2=P2.next
        return P1
```