### 解题思路
一看是nlogn，肯定是归并没跑了
仿照归并排序写了一个链表的归并排序，注意边界条件的判定，由于是链表，似乎不需要开辟空间，所以只是常数空间

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        if not head:
            return 
        def mergesort(head):
            if head.next:
                pre=None
                fast,slow=head,head
                while fast and fast.next:
                    pre=slow
                    slow=slow.next
                    fast=fast.next.next
                if pre:
                    pre.next=None
                p1=mergesort(head)
                p2=mergesort(slow)
                res=merge(p1,p2)
                return res
            else:
                return head
        def merge(p1,p2):
            tmp=Dummy=ListNode(-1)
            while p1 and p2:
                if p1.val<=p2.val:
                    Dummy.next=p1
                    p1=p1.next
                    Dummy=Dummy.next
                else:
                    Dummy.next=p2
                    p2=p2.next
                    Dummy=Dummy.next
            if p1:
                Dummy.next=p1
            else :
                Dummy.next=p2
            return tmp.next
        return mergesort(head)
                    





   
     
```