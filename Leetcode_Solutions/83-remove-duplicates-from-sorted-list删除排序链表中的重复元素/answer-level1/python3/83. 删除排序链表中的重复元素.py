这里用了python的多元变换
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if not head or not head.next: return head
        number, p1, p2 = head.val, head, head.next
        while p2:
            if number ==  p2.val: p1.next, p2 = p2.next, p2.next
            else: p1, p2, number = p2, p2.next, p2.val
        return head