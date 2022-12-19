```
class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if l1 is None:
            return l2
        if l2 is None:
            return l1
        head = ListNode(0) #一个空节点，用于辅助
        current = head #注意这里current 初始化需要是一个节点

        while(l1 or l2):
            if l1 is None:
                current.next = l2
                break
            elif l2 is None:
                current.next = l1
                break
            
            if(l1.val < l2.val):
                current.next = l1
                current = l1
                l1 = l1.next
            else:
                current.next = l2
                current = l2
                l2 = l2.next
        

        
        return head.next
```
