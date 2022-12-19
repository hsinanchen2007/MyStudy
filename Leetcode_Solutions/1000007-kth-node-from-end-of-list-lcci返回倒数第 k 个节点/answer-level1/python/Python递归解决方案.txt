思路就是先递归到尾结点，在回溯的过程中判断k是否为1，不为1就把k-1传到上层递归，若k=1则说明已经找到，返回当前val即可。

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def kthToLast(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: int
        """
        def ToLast(head, k):
            if head is None: return [k, None]
            k, val = ToLast(head.next, k)
            if k == 1: 
                return [k - 1, head.val]
            if k < 1:
                return [k, val]
            return [k - 1, None]

        return (ToLast(head, k))[1]



