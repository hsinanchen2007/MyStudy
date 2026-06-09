```python 
class Solution:
    def removeNthFromEnd(self, head, n):
        global i 
        if head is None:
            i=0
            return None
        head.next = self.removeNthFromEnd(head.next,n)
        i+=1
        return head.next if i==n else head
```