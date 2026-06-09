```
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        """
            删除排序链表中的重复元素 II(非最优解)

            给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
            输入: 1->2->3->3->4->4->5
            输出: 1->2->5
        """
        if not head:
            return None
        # 先找到head
        i = head
        while i.next:
            j = i.next
            if j.val != i.val:
                break
            while j.next and i.val == j.val:
                j = j.next
            if i.val == j.val:
                return None
            i = j
        head = i
        # 再找next
        if i.next:
            k, i, t = i, j, False
            while i.next:
                j = i.next
                total = 0
                while j.next and i.val == j.val:
                    total += 1
                    j = j.next
                if not total and i.val != j.val:
                    k.next = i
                    k = i
                elif i.val == j.val:
                    t = True

                i = j

            k.next = i if not t else None

        return head
```