## 直接上代码
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if not head:return head
        dummy = ListNode(0)
        # dummy.next = head
        
        realNode = dummy
        preNode = dummy
        curNode = head
        
        while curNode:
            if (preNode == dummy or preNode.val != curNode.val) and (curNode.next == None or curNode.val != curNode.next.val):
                realNode.next = curNode
                realNode = realNode.next
            preNode = curNode
            curNode = curNode.next
            preNode.next = None
            
                
        return dummy.next
```


定义虚拟节点dummy，真实节点real 返回值。前驱节点preNode和当前节点curNode