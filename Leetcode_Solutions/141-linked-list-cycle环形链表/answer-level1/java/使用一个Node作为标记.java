    public boolean hasCycle(ListNode head) {
        ListNode flag = new ListNode(-1);
        while (head != null) {
            if (head.next == flag)
                return true;
            ListNode next = head.next;
            head.next = flag;
            head=next;
        }
        return false;
    }