遍历链表，删除目标节点
```   
 public ListNode deleteNode(ListNode head, int val) {
        if (head == null) {
            return null;
        }
        if (head.val == val) {
            return head.next;
        }
        ListNode listNode = head;
        while (listNode != null && listNode.next != null) {
            if (listNode.next.val == val) {
                listNode.next = listNode.next.next;
            }
            listNode = listNode.next;
        }
        return head;
    }
```