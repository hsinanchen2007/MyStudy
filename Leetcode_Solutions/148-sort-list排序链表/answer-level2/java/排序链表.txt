归并排序
```
    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null) return head;
        
        ListNode pre = null, slow = head, fast = head;
        while (fast != null && fast.next != null) {
            pre = slow;
            slow = slow.next;
            fast = fast.next.next;
        }
        pre.next = null;
        
        ListNode l1 = sortList(head);
        ListNode l2 = sortList(slow);
    
        return merge(l1, l2);
  }
    
    private ListNode merge(ListNode l1, ListNode l2){
        if(l1 == null) return l2;
        if(l2 == null) return l1;
        
        if(l1.val > l2.val){
            l2.next = merge(l1, l2.next);
            return l2;
        }else{
            l1.next = merge(l1.next, l2);
            return l1;
        }
    }
```
