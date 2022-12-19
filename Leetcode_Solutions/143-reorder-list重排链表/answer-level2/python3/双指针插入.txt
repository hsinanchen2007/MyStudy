```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if head == None:
            return head

        list1 = []
        now_node = head
        list1.append(now_node)
        while now_node.next:  # 保证list1中加入的一定非None
            now_node = now_node.next
            list1.append(now_node)

        rs_list = list1[0]
        rs_head = rs_list
        l, r = 1, list1.__len__() - 1
        left = False
        while l <= r:
            if left==False:
                rs_list.next = list1[r]
                rs_list = list1[r]
                r -= 1
                left = True
            else:
                rs_list.next = list1[l]
                rs_list = list1[l]
                l += 1
                left = False
        rs_list.next=None
        head=rs_head
```