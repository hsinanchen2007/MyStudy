```
创建两个指针，从head开始一前一后，在遍历时四种情况分开处理：
（1）链表为空或者长度为1，直接返回head
while 快指针指向的节点不为空：
（2）1（慢指向这）->1（快指向这）—>2:快慢指针的值相等，快指针后面还有节点，删除快指针，快慢指针都向前挪一步
（3）1（慢指向这）->2（快指向这）->3:快慢指针的值不等，，快慢指针都向前挪一步
（4）1（慢指向这）->1（快指向这）：快慢指针的值相等，快指针后面没有节点了，慢指针指向的节点的next设为None，跳出循环

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
        if (not head) or (head.next == None):
            return head
        
        p_man = ListNode(0)
        p_kuai = ListNode(1)
        p_man.next = head
        p_kuai.next = head.next
        
        while p_kuai.next:
            if p_man.next.val != p_kuai.next.val:
                p_kuai.next = p_kuai.next.next
                p_man.next = p_man.next.next
            elif p_man.next.val == p_kuai.next.val and p_kuai.next.next:
                p_man.next.next = p_kuai.next.next
                p_kuai.next = p_man.next.next
            else:
                p_man.next.next = None
                break
                
        return head
```
