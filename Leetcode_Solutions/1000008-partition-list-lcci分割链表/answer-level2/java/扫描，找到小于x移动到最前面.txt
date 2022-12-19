```
public ListNode partition(ListNode head, int x) {
        if (head == null) {
            return null;
        }
        
        ListNode cur = head;
        while (cur.next != null) {
            if (cur.next.val < x) {
                ListNode nextNode = cur.next;
                cur.next = nextNode.next;

                nextNode.next = head;
                head = nextNode;
            } else {
                cur = cur.next;
            }
        }
        return head;
    }
```
