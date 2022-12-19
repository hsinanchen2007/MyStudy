执行用时 :40 ms, 在所有 Python3 提交中击败了78.56%的用户
内存消耗 :13.8 MB, 在所有 Python3 提交中击败了21.95%的用户

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteNode(self, node):
        node.val=node.next.val
        node.next=node.next.next
       
```