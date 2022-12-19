```
    public ListNode partition(ListNode head, int x) {
        if (head == null) {
            return null;
        }
        ListNode listNode = new ListNode(-1);
        ListNode cur = listNode;
        ListNode listNode1 = new ListNode(-1);
        ListNode cur1 = listNode1;
        while (head != null) {
            if (head.val < x) {
                listNode.next = head;
                listNode = listNode.next;
            } else {
                listNode1.next = head;
                listNode1 = listNode1.next;
            }
            head = head.next;
        }
        listNode1.next = null;
        listNode.next = cur1.next;
        return cur.next;
    }
```
