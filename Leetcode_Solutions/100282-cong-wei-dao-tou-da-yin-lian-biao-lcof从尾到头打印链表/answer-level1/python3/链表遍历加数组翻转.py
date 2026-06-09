class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        if not head:
            return []
        result = []
        while head:
            result.append(head.val)
            head = head.next
        return result[::-1]