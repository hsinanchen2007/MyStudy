### 解题思路
与一般的删除不同，由于没有链表头节点，因此将该节点的下一节点值复制过来，并将当前节点的指针指向下一节点的指针指向的节点。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        node.val=node.next.val
        node.next=node.next.next
```

![image.png](https://pic.leetcode-cn.com/2381f5ce6cc8638aab61392ff0d5e8e07c79fd9aa8fcde39a42003c10806e6fa-image.png)
