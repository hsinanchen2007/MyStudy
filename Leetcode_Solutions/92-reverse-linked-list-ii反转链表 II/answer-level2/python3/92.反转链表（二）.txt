基本思路：
将链表分为四部分,1~m，m，m~n，n~链表长度。
1. 1~m 和 n~链表长度这两部分，顺序记录。
2. 第m个节点需要翻转到最后，作为中段部分的最后一个节点。
3. m~n 这部分只需依次将新记录的节点放到中段部分最前面。
最后将三段链表连接起来

代码如下：

```
class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        first = f = ListNode(None)
        mid   = ListNode(None)
        last  = l = ListNode(None)
        i = 1
        while head:
            if i<m:
                f.next = ListNode(head.val)
                f = f.next
            elif i==m:
                mid_last = ListNode(head.val)
                mid.next = mid_last
            elif i<=n:
                a = ListNode(head.val)
                a.next = mid.next
                mid.next = a
            else:
                l.next = ListNode(head.val)
                l = l.next
            head = head.next
            i = i+1
        f.next = mid.next
        mid_last.next = last.next
        return first.next
```
