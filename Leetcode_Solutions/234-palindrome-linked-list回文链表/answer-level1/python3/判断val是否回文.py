class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        if not head:
            return True
        val_list = []
        pre = head
        while pre.next!=None:
            val_list.append(pre.val)
            pre = pre.next
        val_list.append(pre.val)
        return val_list == val_list[::-1]