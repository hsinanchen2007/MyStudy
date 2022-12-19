### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
      tmp = []
      while head:
        tmp.append(head.val)
        head = head.next
      i,j = 0,len(tmp)-1
      while i < j:
        tmp[i],tmp[j] = tmp[j],tmp[i]
        i += 1
        j -= 1
      return tmp
```