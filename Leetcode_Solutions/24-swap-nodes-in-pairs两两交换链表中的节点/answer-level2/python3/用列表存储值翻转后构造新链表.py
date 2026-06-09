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
    def swapPairs(self, head: ListNode) -> ListNode:
        new=ptr=ListNode(0)
        res=[]
        while head:
            res.append(head.val)
            head=head.next
        for i in range(0,len(res)-1,2):
            tmp=res[i]
            res[i]=res[i+1]
            res[i+1]=tmp
        for i in res:
            ptr.next=ListNode(i)
            ptr=ptr.next
        return new.next
```