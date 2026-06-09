> 执行用时 : 64 ms, 在所有 Python3 提交中击败了 94.16% 的用户
内存消耗 : 14.5 MB, 在所有 Python3 提交中击败了 11.77% 的用户


```py
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        if k == 1 or head is None or head.next is None:
            return head
        
        # 统计链表长度
        count = 0
        cur = head
        while cur is not None:
            count += 1
            cur = cur.next
        
        # 需要翻转的次数
        count //= k
        # 虚拟节点用来充当“上一次”翻转的最后一个节点
        dummy = ListNode(-1)
        dummy.next = head
        
        cur = dummy
        while count > 0:
            # cur: 上次翻转的最后一个节点
            # last: 本次翻转的第一个节点（翻转后的最后一个节点）
            # pre: 上一个节点（临时）
            # tmp: 当前节点（临时）
            # tmp_next: 下一个节点（临时）
            pre = cur
            last = pre.next
            tmp = last
            for _ in range(k):
                tmp_next = tmp.next
                tmp.next = pre if tmp is not last else None  # last 节点的后继节点先空着，翻转完之后再连
                pre, tmp = tmp, tmp_next
            
            cur.next = pre  # 上一次翻转的最后一个连本次翻转后的头节点
            cur = last  # cur 更新
            last.next = tmp  # 本次翻转的最后一个节点连到下一段的第一个
            count -= 1
        return dummy.next
```