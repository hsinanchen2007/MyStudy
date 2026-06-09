class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        head_list = []
        while head:
            head_list.append(head.val)
            head = head.next
        lenght = len(head_list)
        sum = 0
        for i in range(lenght):
            if head_list[i] == 1:
                sum+=2**(lenght-i-1)
        return sum