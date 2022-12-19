### 解题思路
此处撰写解题思路

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reversePrint(self, head):
        cur=head
        ans=[]
        while cur:
            ans.append(cur.val)
            cur=cur.next
        
        return ans[::-1]
```