```
public ListNode deleteDuplicates(ListNode head) {
        if(head == null)
            return head;
        ListNode p1 = head,p2 = head;
        while (p2 != null){
            if(p1.val == p2.val){
                p2 = p2.next;
            }else {
                p1.next = p2;
                p1 = p2;
            }
        }
        p1.next = p2;
        return head;
    }
```
