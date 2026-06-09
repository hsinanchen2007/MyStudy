    public void reorderList(ListNode head) {
            recursive(head, head);
    }
    public ListNode recursive(ListNode p, ListNode q) {
        if(q == null) return p;

        ListNode cur,next;
        if(q.next == null) cur = p;
        else cur = recursive(p.next, q.next.next);
        next = cur.next;
        if(p.next == cur || p == cur) cur.next = null;
        else {
            cur.next = p.next;
            p.next = cur;
        }
        return next;
    }