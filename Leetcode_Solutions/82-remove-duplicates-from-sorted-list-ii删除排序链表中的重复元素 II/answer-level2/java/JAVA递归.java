```
    public ListNode deleteDuplicates(ListNode head) {
        if(head==null) return head;
        if(head.next!=null&&head.val==head.next.val){
            ListNode p =head.next;
            while(p!=null&&p.val==head.val)
                p=p.next;
            head=p;
            return deleteDuplicates(p);
        }
        else {
            head.next = deleteDuplicates(head.next);
            return head;
        }
    }
```
