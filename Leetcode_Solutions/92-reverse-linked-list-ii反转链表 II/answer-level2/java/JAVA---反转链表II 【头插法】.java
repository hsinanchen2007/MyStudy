使用头插法，具体：
1. 将第m-1个元素当做头（编码时增加一个dummy头，方便操作）;
2. 反转链表的第一个元素作为待反转元素的上一次元素，维护链表关系
```
    public ListNode reverseBetween(ListNode head, int m, int n) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        // p表示头插法的头，q表示反转链表的第一个元素
        ListNode p = dummy, q = head;
        // p定位到反转的起始位置的头
        for (int i = 1; i < m; i++) {
            p = p.next;
        }
        q = p.next;

        for (int i = m; i < n; i++) {
            // 反转链表的头
            ListNode tmp = p.next;
            // 反转链表中的某一个节点
            ListNode tmp2 = q.next;
            // tmp2插入到头的后边
            p.next = tmp2;
            q.next = tmp2.next;
            tmp2.next = tmp;
        }
        return dummy.next;
    }
```