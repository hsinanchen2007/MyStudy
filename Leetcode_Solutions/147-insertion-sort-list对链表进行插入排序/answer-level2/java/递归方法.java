```java
public ListNode insertionSortList(ListNode head) {
        if (head == null) return null;
        ListNode node = head.next, pre = head;
        while (node != null && pre.val <= node.val) {
            node = node.next;
            pre = pre.next;
        }
        if (node == null) return head;
        if (head.val > node.val) {
            pre.next = node.next;
            node.next = head;
            return insertionSortList(node);
        } else {
            ListNode preex = head, ex = head.next;
            while (ex.val <= node.val) {
                ex = ex.next;
                preex = preex.next;
            }
            pre.next = node.next;
            preex.next = node;
            node.next = ex;
            return insertionSortList(head);
        }
    }
```