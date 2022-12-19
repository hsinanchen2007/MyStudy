```
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null) {
            return null;
        }
        ListNode listNode = new ListNode(-1);
        listNode.next = head;
        ListNode cur = listNode;
        while (listNode.next != null && listNode.next.next != null) {
            if (listNode.next.val == listNode.next.next.val) {
                while (listNode.next.next.next != null && listNode.next.val == listNode.next.next.next.val) {
                    listNode.next = listNode.next.next;
                }
                listNode.next = listNode.next.next.next;
            } else {
                listNode = listNode.next;
            }
        }
        return cur.next;
    }
```
