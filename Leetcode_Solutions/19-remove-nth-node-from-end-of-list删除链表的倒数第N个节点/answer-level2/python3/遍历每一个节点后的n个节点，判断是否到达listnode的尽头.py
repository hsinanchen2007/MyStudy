![image.png](https://pic.leetcode-cn.com/eebd045abf84cf97b4a03ccc07b2d49412e3d3eea481fff3cedc07146e75054c-image.png)

**两种方案**

```python []
def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        if head.next == None and n == 1:
            return None
        res = head
        while res.next != None:
            c = res.next
            for i in range(n):
                if c.next == None:
                    if i == n-1:
                        res.next = res.next.next
                        return head
                    else:
                        return head.next
                else:
                    c = c.next
            res = res.next
```
```python []
def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        if head.next == None and n == 1:
            return None
        res = head
        l = 0
        while res != None:
            l += 1
            res = res.next
        res = head
        for i in range(l - n):
            if i == l - n - 1:
                res.next = res.next.next
                return head
            res = res.next
        return head.next
```

