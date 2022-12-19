1. 把链表连接成环
2. 不使用双指针从后往前数k，而是在找尾指针的时候顺便把链表长度给统计了，然后用长度减去需要往前数的k位得到正向后移的位数。
3. 正向后移，然后把环断开。

```python []
class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if not head or not k: return head
        lenth = 1
        temp = head
        while head.next:
            lenth += 1
            head = head.next
        head.next = temp
        l = lenth - (k % lenth)
        while l > 1:
            temp = temp.next
            l -= 1
        r = temp.next
        temp.next = None
        return r
```
