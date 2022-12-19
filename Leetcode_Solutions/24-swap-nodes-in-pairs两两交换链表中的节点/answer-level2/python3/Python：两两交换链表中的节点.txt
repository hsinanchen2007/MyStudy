### 解题思路
还记得前面有一道寻找倒数第n个节点的题吗？
通过相隔n的两个指针一次遍历完成，一模一样的想法

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if head and head.next:
            node=ListNode(0)
            node.next=head
            first=second=node
            first=first.next
            while first and first.next:
                first=first.next
                point=second.next
                second.next=first
                first=first.next
                second.next.next=point
                second=point
                second.next=first
            return node.next
        else:
            return head
```