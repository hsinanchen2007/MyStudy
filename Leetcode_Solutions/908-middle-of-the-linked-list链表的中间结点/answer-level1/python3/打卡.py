### 解题思路
没事好说的
打卡

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        garbage = []
        while 1:
            try:
                garbage.append(head)
                head = head.next
            except:
                break
        size = len(garbage) -1
        pos = size//2
        return garbage[pos]
        
        

```