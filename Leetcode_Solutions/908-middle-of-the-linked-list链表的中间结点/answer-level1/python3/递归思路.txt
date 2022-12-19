### 解题思路
根据链表的长度，返回最终的位置值

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        #递归
        
        def getmiddle(head,deepth,finalnode):
            if not head:return (((deepth-1)//2+1 if (deepth-1)%2 else (deepth-1)//2)\
            ,finalnode) 
            finaldeepth,finalnode=getmiddle(head.next,deepth+1,finalnode)
            if finaldeepth==deepth:
                finalnode=head
            return finaldeepth,finalnode
        
        finaldeepth,finalnode=getmiddle(head,0,None)
        return finalnode

```