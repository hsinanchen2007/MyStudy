class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        "递归法"
        """l1和l2其中一个为空或者都为空"""
        if not (l1 and l2):
            return l1 if l1 else l2

        if l1.val <= l2.val:
            # 比较l1的下一个和l2哪个大，较小的那一个作为l1的下一个节点
            l1.next = self.mergeTwoLists(l1.next, l2)
            return l1

        else:
            # 比较l2的下一个和l1哪个大，较小的那一个作为l2的下一个节点
            l2.next = self.mergeTwoLists(l1, l2.next) 
            return l2


class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        """穿针引线法"""
        res = ListNode(None)
        # 存储头结点
        p = res
        while (l1 and l2):
            if l1.val <= l2.val:
                p.next = l1
                l1 = l1.next
            else:
                p.next = l2
                l2 = l2.next
            p = p.next

        # 如果l1为空则将l1剩下的元素拼接到p节点后面，否则拼接l2
        p.next = l1 if l1 else l2

        return res.next