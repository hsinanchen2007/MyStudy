### 解题思路
把节点装列表里收尾双指针遍历，
注意最后res[left].next=None，
最后一个节点指向空而不是它的下一个，
注意head==None的情况要单列出来，不然后续head.next会空指针报错
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if head==None:
            return None
        res=[]
        while head:
            res.append(head)
            head=head.next
        left=0
        right=len(res)-1
        while left!=right:
            if left!=right:
                res[left].next=res[right]
                left+=1
            if left!=right:
                res[right].next=res[left]
                right-=1
        res[left].next=None








```