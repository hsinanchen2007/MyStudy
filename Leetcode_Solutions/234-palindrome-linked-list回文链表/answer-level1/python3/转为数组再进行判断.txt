class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        if not head or not head.next:
            return True
        tmp = []
        while head:
            tmp.append(head.val)
            head = head.next
        return tmp[:] == tmp[::-1]