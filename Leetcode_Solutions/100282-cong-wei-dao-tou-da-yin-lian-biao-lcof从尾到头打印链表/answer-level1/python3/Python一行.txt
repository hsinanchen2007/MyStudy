class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        return self.reversePrint(head.next)+[head.val] if head else []