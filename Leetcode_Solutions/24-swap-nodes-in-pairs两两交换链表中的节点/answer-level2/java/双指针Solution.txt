```
    public ListNode swapPairs(ListNode head) {
        if(null == head){
            return head;
        }
        ListNode dump = new ListNode(-1);
        ListNode slow = dump, fast = head;
        slow.next = fast;
        while(null != slow && null != fast && null != fast.next){
            slow.next = fast.next;
            slow = fast.next;
            fast.next = slow.next;
            slow.next = fast;
            slow = fast;
            fast = fast.next;
        }
        return dump.next;
    }
```