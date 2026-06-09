### 解题思路
遍历每个节点，每次都插入到列表的第一个位置

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reversePrint(self, head):
        """
        :type head: ListNode
        :rtype: List[int]
        """
        if head == None:
            return []
        
        res = []
        while head != None:
            res.insert(0, head.val)
            head = head.next

        return res
```