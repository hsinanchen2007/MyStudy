### 解题思路
迭代,记录每两个节点的连接关系；
能用迭代就迭代，递归有额外空间开销。
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        curNode = head
        newNode = None
        while(curNode is not None):
            posNode = curNode.next
            curNode.next = newNode
            newNode = curNode
            curNode = posNode
        return newNode 


```