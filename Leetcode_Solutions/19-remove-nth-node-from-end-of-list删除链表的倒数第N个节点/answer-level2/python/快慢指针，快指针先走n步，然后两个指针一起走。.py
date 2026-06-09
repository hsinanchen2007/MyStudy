首先先判断了下删除的是否是最后一个节点， `if n == 1:`的内部又判断了链表是否为单节点链表。  
因为如果直接使用下面的快慢指针的话，当删除最后一个节点时，`slow.next = slow.next.next`会报错。  
暂时没有想到更好的优化方案了，求大佬优化重构。
```
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        dummy = ListNode(0)
        dummy.next = head
        
        # 判断是否删除的最后一个节点
        if n == 1:
            if head.next == None:
                dummy.next = None
                return dummy.next
            while head.next:
                tmp = head
                head = head.next
                print(tmp.val, head.val)
            tmp.next = None
            return dummy.next
        
        fast, slow = head, head
        # 快慢指针，fast先走n步，slow再走
        for _ in range(n):
            fast = fast.next

        while fast:
            fast = fast.next
            slow = slow.next
            
        slow.val = slow.next.val
        slow.next = slow.next.next
        
        return dummy.next
            
```