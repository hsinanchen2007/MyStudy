### 解题思路
递归算法要点：
    1 结束条件
    2 规律

结束条件是： 既然肯定是有序，只要两者有一个为空，返回另一个即可

规律是：找到最小的点n1，然后将其余的点的最小的点n2赋值给n1.next，而想要求出n2的next，则需要找到n3，想要求n3的next，则要求出n4....
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if not l1:
            return l2
        if not l2:
            return l1
        
        min_node, max_node = (l1, l2) if l1.val <= l2.val else (l2, l1)
        next_node = min_node.next
        min_node.next = self.mergeTwoLists(next_node, max_node)
        return min_node
```
