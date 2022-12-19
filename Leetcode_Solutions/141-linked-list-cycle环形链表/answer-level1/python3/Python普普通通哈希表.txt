### 解题思路
记录访问过的位置

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        dic = {}
        node = head
        while(node):
            if(dic.get(node,0) != 0):
                return True
            else:
                dic[node] = 1
            node = node.next
        return False
        
```