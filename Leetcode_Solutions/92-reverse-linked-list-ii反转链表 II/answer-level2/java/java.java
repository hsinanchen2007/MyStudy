

```
public ListNode reverseBetween(ListNode head, int m, int n) {

        ListNode res = new ListNode(0);
        res.next = head;
        ListNode node = res;
        //找到需要反转的那一段的上一个节点。
        for (int i = 1; i < m; i++) {
            node = node.next;
        }

        //node.next就是需要反转的这段的起点。
        ListNode nextHead = node.next;
        ListNode next = null;

        ListNode pre = null;

        //反转n到m这一段
        for (int i = 0; i <= n - m; i++) {
            next = nextHead.next;
            nextHead.next = pre;
            pre = nextHead;
            nextHead = next;
        }
        //需要反转的那一段的上一个节点的next节点指向反转后链表的头结点
        node.next = pre;
        //找到反转这段的最后一个节点。
        while (pre.next != null) {
            pre = pre.next;
        }
        pre.next = next;
        return res.next;
    }
```
