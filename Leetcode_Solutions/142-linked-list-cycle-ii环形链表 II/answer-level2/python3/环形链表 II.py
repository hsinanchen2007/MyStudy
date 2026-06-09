我看很多人都在写龟兔赛跑的方法，其实大部分人的第一反应应该是这样的吧。
```python
class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head == None:
            return None
        
        res = {head}
        while head.next:
            if head.next in res:
                return head.next
            else:
                res.add(head.next)
                head = head.next
        return None
```
在这里应该注意一点，如果没有返回的是`None`。