### 解题思路
直接遍历反转即可，或者再把ans里的东西pop到另外一个列表里

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        if not head:
            return []
        ans = []
        cur = head 
        while(cur):
            ans.append(cur.val)
            cur = cur.next
        
        return list(reversed(ans))
            
```