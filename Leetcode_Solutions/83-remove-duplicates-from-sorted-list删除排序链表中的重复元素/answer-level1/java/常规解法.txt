```
public ListNode deleteDuplicates(ListNode head) {
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        while (head != null){
            ListNode cur = head;
            while (head.next != null && head.val == head.next.val){
                head = head.next;
            }
            cur.next = head.next;
            head = head.next;
        }
        return dummy.next;
    }
```
