### 解题思路
在这用双指针一直下去就可以了

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        # 按照节点编号的奇偶性来分，那么就有个n来计数，或者双指针迭代
        # 然后要求用原地算法，和n的时间复杂度
        if head is None or head.next is None or head.next.next is None:
            return head
        odd_num = head
        even_num = head.next
        even_head = even_num
        while even_num and even_num.next:
            odd_num.next = even_num.next
            odd_num = odd_num.next
            even_num.next = odd_num.next
            even_num = even_num.next
        odd_num.next = even_head
        return head
```