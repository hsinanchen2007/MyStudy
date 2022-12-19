```
public ListNode insertionSortList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        ListNode dummy = new ListNode(0);

        ListNode node = head;

        while (node != null) {
            ListNode nextNode = node.next;

            ListNode w = dummy.next;
            ListNode preW = dummy;

            while (w != null && w.val < node.val) {
                w = w.next;
                preW = preW.next;
            }
            preW.next = node;
            node.next = w;

            node = nextNode;
        }

        return dummy.next;
    }
```
