```
public ListNode rotateRight(ListNode head, int k) {
        if (head == null) return null;
        if (k == 0) return head;
        ListNode h = head;

        ListNode end = head;
        int len = 0;
        while (h != null){
            len ++;
            end = h;
            h = h.next;
        }
        if (k % len == 0) return head;
        k = k % len;

        ListNode res = head;
        ListNode fast = head;
        ListNode x = head;
        while (k -- > 0){
            fast = fast.next;
        }
        while (fast != null){
            x = res;
            fast = fast.next;
            res = res.next;
        }
        x.next = null;
        end.next = head;
        return res;
    }
```
