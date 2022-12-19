 注意删除头节点的情况

```
public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode nnode = head;
        ListNode pre = head;
        for (int i = 0; i < n; i++) {
            nnode = nnode.next;
        }
        if (nnode == null) {
            head = head.next;
        } else {
            while (nnode.next != null) {
                pre = pre.next;
                nnode = nnode.next;
            }
            pre.next = pre.next.next;
        }
        return head;
    }
```
