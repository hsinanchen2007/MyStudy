```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        # 头插法
        # a -> b -> c -> d
        if not head:
            return head
        
        cur = head.next
        dummyHead = head
        node = head
        
        head.next = None # 切断当前的head最终指向
        
        while cur != None:
            node = ListNode(cur.val) # 需要重建新的node节点
            print(cur.val)
            node.next = dummyHead
            dummyHead = node
            cur = cur.next
            
        
        return dummyHead
            
```
这种解法中，使用的是头插法，但是注意头插法时需要生成新的节点`node`，否则会指向同一个节点，导致cur陷入死循环。

END.