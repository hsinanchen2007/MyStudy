__思路__：

1.遍历第一遍，求出链表长度，并获得最后一个节点。

2.将链表首尾相接。

3.题目中头结点是向前挪k%len次，但程序中只能往后挪，所以将头节点向后挪 len - (k%len) 次。

4.断开链表，取回结果。

```
class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if not head or not head.next: return head
        first = head
        len_list = 1
        while head.next:
            len_list += 1
            head = head.next
        head.next = first
        for i in range(len_list - k % len_list):
            head = head.next
        result = head.next
        head.next = None
        return result
```