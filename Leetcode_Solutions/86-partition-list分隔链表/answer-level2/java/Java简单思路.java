思路：
1. 将小于x的点依次存入一个链表
2. 将大于等于x的点依次存入另一个链表
3. 将两个链表拼接在一起
```
        ListNode l1 = new ListNode(-1);
        ListNode l2 = new ListNode(-1);
        ListNode p1 = l1;
        ListNode p2 = l2;
        while (head != null) {
            if (head.val < x) {
                p1.next = head;
                p1 = p1.next;
            } else {
                p2.next = head;
                p2 = p2.next;
            }
            head = head.next;
        }
        p2.next = null;
        p1.next = l2.next;
        return l1.next;
```
