数组法：
```python []
class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        vals, ans = [], head
        while head:
            vals.append(head.val)
            head = head.next
        head = ans
        for val in vals[:: 2] + vals[1:: 2]:
            head.val = val
            head = head.next
        return ans
```
原地法1：
```python []
class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        odd, even = ListNode(0), ListNode(0)
        oddeven, t = [odd, even], 0
        while head:
            oddeven[t].next = head
            oddeven[t], head, t = head, head.next, t ^ 1
        oddeven[0].next, oddeven[1].next = even.next, None
        return odd.next
```
原地法2：
```python []
class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        if not head:
            return None
        odd, even = head, head and head.next
        o, e = odd, even
        while e and e.next:
            o.next, e.next = o.next.next, e.next.next
            o, e = o.next, e.next
        o.next = even
        return odd
```


![image.png](https://pic.leetcode-cn.com/0e2c1a270e971b0fddecdb6b4ca10e3a0306aa20ef500307f5c888f63ca4e4b6-image.png)
