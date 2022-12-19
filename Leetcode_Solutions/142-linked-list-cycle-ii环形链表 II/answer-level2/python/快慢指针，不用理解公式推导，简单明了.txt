```
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
        :思路：第一步：快指针一次移动2步，慢指针移动1步，如果快指针追上慢指针，证明有环
               第二步：用慢指针循环一圈计算环的长度
               第三步： 快指针先走环的长度，慢指针再开始走，交汇节点即为入环节点
        """
        
        if head == None or head.next == None:
            return None
        
        fast_node = head.next
        slow_node = head
        circle_len = 1
        
        while fast_node.next and fast_node.next.next:
            if slow_node == fast_node or slow_node == fast_node.next:
                # 如果有环，计算环的长度
                tmp_node = slow_node
                while slow_node.next != tmp_node:
                    slow_node = slow_node.next
                    circle_len += 1
                
                # 快指针先走环的长度，慢指针再走，慢指针和快指针交汇处即为入环第一个点
                slow_node = head    
                fast_node = head
                while circle_len:
                    fast_node = fast_node.next
                    circle_len -= 1                
                while slow_node != fast_node:
                    fast_node = fast_node.next
                    slow_node = slow_node.next    
                return slow_node
            
            else:        
                fast_node = fast_node.next.next
                slow_node = slow_node.next
        
        return None
```
