### 解题思路
1. 递归，每次递归互相交换两个值，返回第second_node，同事second_node.next = first_node
2. 迭代

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        # if not head or not head.next:
        #     return head
        
        # first_node = head
        # second_node = head.next

        # first_node.next = self.swapPairs(second_node.next)
        # second_node.next = first_node

        # return second_node

        dumpy = ListNode(-1)
        dumpy.next = head
        prev = dumpy

        while head and head.next:
            first_node = head
            second_node = head.next

            prev.next = second_node
            first_node.next = second_node.next
            second_node.next = first_node

            prev = first_node
            head = first_node.next
        return dumpy.next



```