
操作理论都被大神讲的差不多了，就把自己的解题结果上传了，仅供参考，如果有不对的地方还请指正

```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        return self.add_two(l1, l2)

    def add_two(self, l1, l2, add_value=0):
        if not l1 and not l2 and add_value == 0:
            return None

        l1_value = l1.val if l1 else 0
        l2_value = l2.val if l2 else 0
        node_val = l1_value + l2_value + add_value

        l1_next = l1.next if l1 else None
        l2_next = l2.next if l2 else None

        if node_val >= 10:
            result_node = ListNode(node_val-10)
            result_node.next = self.add_two(l1_next, l2_next, 1)
        else:
            result_node = ListNode(node_val)
            result_node.next = self.add_two(l1_next, l2_next)

        return result_node
```
