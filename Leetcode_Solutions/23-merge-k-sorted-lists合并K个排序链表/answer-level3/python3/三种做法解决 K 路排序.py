### 解题思路
三种最优做法。
第一种，列表中链表两两归并排序（比如12,34,56归并），最后单数的轮空进入下一轮，重复直到只剩最后一个链表既是结果。时间复杂度O(nlogk)
第二种，同样是两两归并排序，只是采用分治的写法。时间复杂度O(nlogk)
第三种，使用最小堆维护当前链表数组中最小头结点和对应的索引，pop 的同时把后续节点入堆，直到所有堆空为止。时间复杂度O(nlogk)

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

from heapq import *

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        # return self.mergeKLists1(lists)
        # return self.mergeKLists2(lists)
        return self.mergeKLists3(lists)

    def mergeKLists1(self, lists):
        if len(lists) == 0:
            return []

        lst = lists[:]
        while len(lst) > 1:
            t = []
            for i in range(0, len(lst) // 2 * 2, 2):
                t.append(self.mergeTwoList(lst[i], lst[i+1]))
            if len(lst) % 2 == 1:
                t.append(lst[-1])
            lst = t
        return lst[0]


    def mergeKLists2(self, lists):
        if len(lists) == 0:
            return None
        if len(lists) == 1:
            return lists[0]

        mid = len(lists) // 2
        return self.mergeTwoList(self.mergeKLists2(lists[:mid]), self.mergeKLists2(lists[mid:]))


    def mergeKLists3(self, lists):
        h = []
        for i in range(len(lists)):
            if lists[i]:
                heappush(h, (lists[i].val, i))

        dummy = tail = ListNode(0)
        while h:
            val, i = heappop(h)
            tail.next = lists[i]
            tail = tail.next
            lists[i] = lists[i].next
            if lists[i]:
                heappush(h, (lists[i].val, i))

        return dummy.next


    def mergeTwoList(self, list1, list2):
        dummy = tail = ListNode(0)
        while list1 and list2:
            if list1.val < list2.val:
                tail.next = list1
                list1 = list1.next
            else:
                tail.next = list2
                list2 = list2.next
            tail = tail.next
        if list1:
            tail.next = list1
        if list2:
            tail.next = list2
        return dummy.next

```