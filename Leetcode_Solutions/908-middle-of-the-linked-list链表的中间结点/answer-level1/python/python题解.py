```
class Solution(object):
    def middleNode(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        temp = head
        result = []
        while temp:
            result.append(temp)
            temp = temp.next
        result[-1].next = None
        return result[len(result)//2]
```
