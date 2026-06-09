``` python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # 你应当保留两个分区中每个节点的初始相对位置。 简单的 partition 无法实现此。
    # 如下代码无法实现上述要求. 难怪快排不稳定。
    def partition(self, head: ListNode, x: int) -> ListNode:
        i, j = head, head
        while j:
            if j.val < x:   # 这里到底要不要控制 = 
                i.val, j.val = j.val, i.val
                i = i.next
            j = j.next
        return head
```