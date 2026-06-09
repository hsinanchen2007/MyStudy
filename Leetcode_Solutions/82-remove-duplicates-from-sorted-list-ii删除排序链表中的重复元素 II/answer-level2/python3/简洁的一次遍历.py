```
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """   
        if head == None:
            return head
        
        pre_node = ListNode(0)   #设置一个头节点
        pre_node.next = head
        p = pre_node
        q = head
        guard = 0  #guard用于记录是不是出现了相同元素
        
        while q.next != None:
            if guard == 1:
                q = q.next
                p.next = q #删除操作
                guard = 0
                
            while q.next != None and q.val != q.next.val:
                p = q
                q = q.next

            while q.next != None and q.val == q.next.val:
                q = q.next
                guard = 1
                
        if guard == 1:   #由于上面循环的中止条件是q.next是不是空。f故如果List的最后几个元素是相等的，需要补一个删除操作
            q = q.next
            p.next = q  #删除操作
        
        return pre_node.next
```
