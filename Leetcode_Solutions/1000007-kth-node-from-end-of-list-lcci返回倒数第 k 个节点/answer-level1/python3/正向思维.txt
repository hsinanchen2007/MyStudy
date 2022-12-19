class Solution:
    def kthToLast(self, head: ListNode, k: int) -> int:
        count = 0
        cur = head
        while head:
            count += 1
            head = head.next
        index = count - k
        for i in range(index):
            cur = cur.next
        return cur.val

# 思路: 寻找倒数第K个值，反向思维就是正向的链表减K的下表值 ， index = count - k 
# 其中count为整个链表的长度， 这样时间复杂度就为O(n)