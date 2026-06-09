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
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        list=[]
        if l1==None and l2==None:
            return None
        while l1:
            list.append(l1.val)
            l1=l1.next
        while l2:
            list.append(l2.val)
            l2=l2.next
        list = sorted(list)
        t= ListNode(list[0])
        l=t
        i=1
        while i < len(list):
            t.next=ListNode(list[i])
            t=t.next
            i+=1
        return l
            

        
        
```