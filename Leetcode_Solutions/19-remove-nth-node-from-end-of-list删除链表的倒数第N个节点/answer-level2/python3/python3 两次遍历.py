### 解题思路
详见代码

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        if not head or n<=0:
		        return head
        headcopy=head
        count=0#计算链表数目
        while head is not None:
            count+=1
            head=head.next
        if count==1:#链表内只有一个
            return None
        elif n==count:#要删除的是头节点
            return headcopy.next
        pre=headcopy
        num=1#找到要删除节点的前一个结点
        while num<count-n:
            pre=pre.next
            num+=1
        pre.next=pre.next.next
        return headcopy
```