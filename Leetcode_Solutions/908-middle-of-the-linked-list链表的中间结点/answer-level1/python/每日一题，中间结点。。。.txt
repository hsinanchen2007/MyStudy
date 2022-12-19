### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
import math
class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        # 定义域 head-》next ！= None
        it = head
        size = 1
        while it.next != None:
            size += 1
            it = it.next
        if size == 1:
            return head
        # [1,2,3]
        # g =3/2 = 2
        # g=1 it2 = 2
        print(size)
        g = size//2
        print(g) 
        it2 = head
        while g!=0:
            it2=it2.next
            g -= 1
        return it2
```