```
public void reorderList(ListNode head) {
        if (head == null)
            return;
        ListNode slow = head;
        ListNode fast = head.next;
        while (fast != null){
            fast = fast.next;
            if (fast == null)
                break;
            fast = fast.next;
            slow = slow.next;
        }
        fast = slow.next;
        slow.next = null;
        slow = head;
        //反转
        ListNode tmp = null;
        ListNode pre = null;
        while (fast != null){
            tmp = fast.next;
            fast.next = pre;
            pre = fast;
            fast = tmp;
        }
        while (pre != null){
            tmp = slow.next;
            slow.next = pre;
            pre = pre.next;
            slow.next.next = tmp;
            slow = tmp;
        }
    }
```
