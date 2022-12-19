### 解题思路
由此题可见python中的heapq默认小根堆
主要涉及代码由：
heapq.heappush(myheap, (node.val, index)) # 无返回值，第二个选项为存进去的值，其中第一个值是用来比较的权值
value, index = heapq.heappop(myheap)


### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
import heapq

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        myheap = []
        for index, node in enumerate(lists):
            if node:
                heapq.heappush(myheap, (node.val, index))
        head = ListNode(-1)
        now = head
        while myheap:
            value, index = heapq.heappop(myheap)
            now.next = ListNode(value)
            now = now.next
            lists[index] = lists[index].next
            if lists[index]:
                heapq.heappush(myheap, (lists[index].val, index))
        return head.next

```