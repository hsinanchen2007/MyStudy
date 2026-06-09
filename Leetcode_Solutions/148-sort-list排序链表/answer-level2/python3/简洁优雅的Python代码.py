```python
class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        def merge(l1,l2):
            if not l1: return l2
            if not l2: return l1
            if l1.val<l2.val:
                l1.next = merge(l1.next,l2)
                return l1
            l2.next = merge(l1,l2.next)
            return l2
        
            
        def cut(head):
            if not head :
                return None,None
            s,f = head,head.next
            while f and f.next:
                s = s.next
                f = f.next.next
            right = s.next
            s.next = None
            return head,right
        
        def mergeSort(head):
            if not head or not head.next:
                return head
            left,right = cut(head)
            l1 = mergeSort(left)
            l2 = mergeSort(right)
            return merge(l1,l2)
        
        return mergeSort(head)
```