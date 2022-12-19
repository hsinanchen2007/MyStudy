class Solution1(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        pre = None
        curr = head
        while curr:
            tem = curr.next
            curr.next = pre
            pre = curr
            curr = tem
        return pre