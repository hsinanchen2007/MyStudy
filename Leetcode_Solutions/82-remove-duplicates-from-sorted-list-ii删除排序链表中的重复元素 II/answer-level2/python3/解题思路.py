### 解题思路
遍历链表，用map{int,value}记录重复元素,再依判断map元素大于1时，则删除链表的节点，剩下的节点再构建新的链表，返回结果

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        currnode = head
        valdict = {}
        while currnode:
            if currnode.val in valdict:
                valdict[currnode.val] += 1
            else:
                valdict[currnode.val]=1
            currnode = currnode.next

        currnode = head
        newhead = None
        newcurr = None
        while currnode:
            if valdict[currnode.val] == 1:
                node=ListNode(currnode.val)
                if newhead is None: #new a list
                    newhead = node
                    newcurr=newhead
                else:
                    newcurr.next = node
                    newcurr = newcurr.next
            currnode = currnode.next
        return newhead
```