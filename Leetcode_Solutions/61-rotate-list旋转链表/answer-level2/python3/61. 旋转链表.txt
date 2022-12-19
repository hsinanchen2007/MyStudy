
数组法
```python []
class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if not head or not head.next or not k:
            return head
        vals = []
        while head:
            vals.append(head.val)
            head = head.next
        vals = vals[-k % len(vals): ] + vals[: -k % len(vals)]
        ans = tmp = ListNode(None)
        for val in vals:
            tmp.next = ListNode(val)
            tmp = tmp.next
        return ans.next
```

双指针法
```python []
class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if not head or not head.next:
            return head
        tmp = ans = head
        i = 0
        while i < k:
            head = head.next
            i += 1
            if not head:
                head = tmp
                i, k = 0, k % i
        if head is ans:
            return ans
        while head.next:
            ans = ans.next
            head = head.next
        head.next, ans.next, ans = tmp, None, ans.next
        return ans
```

![image.png](https://pic.leetcode-cn.com/d944bbe3eaaa9f0b38d32146658423e4cda72c71b2292a51ec657107ccaecc97-image.png)
