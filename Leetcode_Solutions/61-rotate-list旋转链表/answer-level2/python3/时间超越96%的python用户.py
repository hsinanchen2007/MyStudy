想法是：旧的表头需要向前走need步，得到新表头，need = 链表总长 - k%链表总长，然后把表尾与旧表头连接，新表头的前一位置指向None
举个例子：链表1-2-3-4-5，总长为5，k为2，则need= 3，即表头需要走3步，从1走到4，让表尾与旧表头连接，即5-1，新表头的前一位置指向None，即3-None
```
class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if head is None:
            return None
        rear = head
        count = 1
        while rear.next != None:
            count += 1
            rear = rear.next
        if count == 1 or k == 0 or k%count == 0:
            return head
        need = count - k%count
        pre = None
        cur = head
        while need > 0:
            need -= 1
            pre = cur
            cur = cur.next
        rear.next = head
        head = cur
        pre.next = None
        return head
```

