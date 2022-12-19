很多答案都用的是双指针。用的是上数据结构课讲得**头插法**进行链表反转
```
    public ListNode reverseList(ListNode head) {
        if (head == null) return null;
        ListNode p = head.next;
        ListNode head1 = new ListNode(head.val);
        while (p != null) {
            ListNode node = new ListNode(p.val);
            node.next = head1;
            head1 = node;
            p = p.next;
        }
        return head1;   
    }
```

