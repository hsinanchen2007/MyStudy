### 解题思路
此处撰写解题思路
递归解决
### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeTwoList(self,l1,l2):
        temp=head=ListNode(None)
        while(l1 and l2):
            if l1.val<=l2.val:
                head.next=l1
                head=l1
                l1=l1.next
            else:
                head.next=l2
                head=l2
                l2=l2.next
        if(l1):
            head.next=l1
        if(l2):
            head.next=l2
        return temp.next

    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        if(len(lists)==0):
           return None
        if(len(lists)==1):
            return lists[0]
        if(len(lists)==2):
            return self.mergeTwoList(lists[0],lists[1])
        
        k=len(lists)
        l1=lists[:k/2]
        l2=lists[k/2:]
        subList1=self.mergeKLists(l1)
        subList2=self.mergeKLists(l2)

        return self.mergeTwoList(subList1,subList2)

```