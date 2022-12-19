使用快慢指针法即可
![UC截图20191204202236.png](https://pic.leetcode-cn.com/2a376c80e6013547a33db705f90cc406fcda37d1a442cb150228bd6ac6d6f5bb-UC%E6%88%AA%E5%9B%BE20191204202236.png)
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        if head == None or head.next == None:
            return head
        dummy = ListNode(float('inf'))
        dummy.next = head
        slow = dummy
        pre = fast = dummy.next
        while fast:
            if fast.val < x and (fast == head or pre.val < x):
                slow = fast
                pre = fast
                fast = fast.next
            elif fast.val < x and fast != head:
                pre.next = fast.next
                fast.next = slow.next
                slow.next = fast
                slow = fast
                fast = pre.next       
            else:
                pre = fast
                fast = fast.next
        return dummy.next    
        
```
