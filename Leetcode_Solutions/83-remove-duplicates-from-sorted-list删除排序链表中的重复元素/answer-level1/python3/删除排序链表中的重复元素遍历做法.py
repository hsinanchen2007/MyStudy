# 遍历求解

这个题很简单，遍历链表的节点，和后一个节点比较val值是否相等，相等则将后一个节点的后一个节点链到该节点后，一次遍历搞定，代码清晰

```
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:        
        tmp_node=head
        
        while(head):
            
            if not head.next:
                break
            if head.val==head.next.val:
                head.next = head.next.next
                
            else:
                head = head.next
                
        return tmp_node
```
