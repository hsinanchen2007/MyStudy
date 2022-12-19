### 解题思路

先求出链表长度，然后使用快慢指针，和删除链表倒数第N个节点相似

### 代码

```
class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if not head or not head.next or k<=0:return head
        length = 1
        cur = head
        while cur.next:
            length+=1
            cur = cur.next

        k = k%length
        if k == 0:
            return head
        fast =head
        slow = head
        while k>0 and fast:
            fast = fast.next
            k-=1

        while fast.next:
            slow = slow.next
            fast = fast.next
        fast.next = head
        new_head = slow.next
        slow.next = None
        return new_head
```