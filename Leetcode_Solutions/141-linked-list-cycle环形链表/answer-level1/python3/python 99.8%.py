# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        # 题意：判断链表中是否存在环
        # 思路：双指针，当双指针相遇则说明其有环，当前一指针指向None时，说明无环
        #       关键在于怎么让两指针相遇
        # 1.若前一指针不为空
        # 2.若两指针相遇，有环；反之，后指针向前移动一次，前一指针向前移动两次，若有环，一定会相遇
        # 3.若前一指针为空，说明无环
        # 特殊测试用例：[],-1; [1,2],-1; [1],-1
        if head==None:
            return False
        p1 = head
        p2 = head.next
        while p2:
            if p2.next==None:
                return False
            if p2 == p1:
                return True
            p1 = p1.next
            p2 = p2.next.next
        return False