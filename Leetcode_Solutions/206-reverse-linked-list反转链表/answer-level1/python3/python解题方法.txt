### 解题思路
依次取出节点值插入新链表的最后

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        result=None
        def reverse(num,res):
            tempNode=ListNode(num)
            tempNode.next=res
            return tempNode
        while head!=None:
            result=reverse(head.val,result)
            head=head.next

        return result
```