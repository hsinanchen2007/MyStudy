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
        : 思路：判断当前节点后的两个节点值，如果不相等，当前节点向前移动一次，
                如果相等，循环向前找到与其不相等的节点，当前节点next指向不相等的节点
                相当于删除中间值相同的节点
        """
        
        if head == None or head.next == None:
            return head
        
        dummy_node = ListNode(0) # 哑节点
        dummy_node.next = head
        cur_node = dummy_node
        
        while cur_node.next and cur_node.next.next:
            if cur_node.next.val != cur_node.next.next.val:
                cur_node = cur_node.next
            else: # 后两个节点值相等时，向前直到找到不相等节点
                tmp_node = cur_node.next
                while tmp_node.next and tmp_node.val == tmp_node.next.val:  
                    tmp_node = tmp_node.next                   
                cur_node.next = tmp_node.next
 
        return dummy_node.next
```
