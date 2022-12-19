### 解题思路
遍历节点把值装进列表再反转，索引对应该元素左移几位

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        res=[]
        while head:
            res.append(head.val)
            head=head.next
        res=res[::-1]
        sum=0
        for i,x in enumerate(res):
            sum+=x<<i
        return sum
```