### 解题思路
reverse_m_n函数将last后面的第m到n个节点反转，无返回值，可用作任何情况下的反转链表

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """


        def reverse_n(head, n):
             
            last = head  
            node = last.next

            count = 1
            while count < n:
                next = node.next 
                node.next = last
                last = node 
                node = next
                count += 1

            head.next = node
            return last 


        def reverse_m_n(last, m, n):
            count = 1
            head = last.next
            while count < m:
                count += 1
                last = head
                head = head.next 
            last.next = reverse_n(head, n - m + 1)


        dummy = ListNode(None)
        dummy.next = head
        
        start = dummy
        node = start
        count = 0
        while node:
            if count < k:
                count += 1
                node = node.next 
            else:
                count = 0
                cur_tail = start.next 
                reverse_m_n(start, 1, k)
                start = cur_tail
                node = start
        return dummy.next
        


```