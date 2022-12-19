```
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        # 方法1：哈希法，其实同置空法一样，后者用于可修改原结构的情况，不需要额外空间
        visited = set()
        while headA:
            visited.add(headA)
            headA = headA.next
        while headB:
            if headB in visited:
                return headB
            headB = headB.next
        return None
        
        # 方法2：先遍历法
        # lenShort = lenLong = 0
        # node = headA
        # while node:
        #     node = node.next
        #     lenShort += 1
        # node = headB
        # while node:
        #     node = node.next
        #     lenLong += 1
        # if lenLong<lenShort: # headA始终记录更短链表的头
        #     headA, headB = headB,headA
        # for _ in range(abs(lenLong-lenShort)):  # 先将长的链表挪到同短的链表头到交点同样距离的位置
        #     headB = headB.next
        # while headA:
        #     if headA == headB:  # 找到了
        #         return headA
        #     headA = headA.next
        #     headB = headB.next
        # return None
```
