
![image.png](https://pic.leetcode-cn.com/19da37dcf1ada7a31ecde81830088f2628d98bd8c0ee5b9b6d55feba2f2c3a49-image.png)
```python
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        flag = 0
        out = r = ListNode(0)
        while l1 is not None and l2 is not None:
            temp = l1.val + l2.val + flag
            if temp >= 10:
                flag = 1
                p = temp - 10
            else:
                flag = 0
                p = temp
            l1 = l1.next
            l2 = l2.next
            r.next = ListNode(p)
            r = r.next
        while l1 is not None:
            temp = l1.val + flag
            if temp >= 10:
                flag = 1
                p = temp - 10
            else:
                flag = 0
                p = temp
            l1 = l1.next
            r.next = ListNode(p)
            r = r.next
        while l2 is not None:
            temp = l2.val + flag
            if temp >= 10:
                flag = 1
                p = temp - 10
            else:
                flag = 0
                p = temp
            l2 = l2.next
            r.next = ListNode(p)
            r = r.next
        if flag:
            r.next = ListNode(1)
        out = out.next
        return out
```
