public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode prev=new ListNode();
        prev.next=head;
        ListNode slow=prev;
        ListNode fast=prev;
        while(n!=0){
            fast=fast.next;
            n--;
        }
        while(fast.next!=null){
            fast=fast.next;
            slow=slow.next;
        }
        slow.next=slow.next.next;
        return prev.next;
    }