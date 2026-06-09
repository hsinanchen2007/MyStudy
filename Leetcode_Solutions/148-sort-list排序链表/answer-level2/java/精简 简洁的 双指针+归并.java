public ListNode sortList(ListNode head) {
    if (head == null || head.next == null) return head;
    ListNode slow = head;
    ListNode fast = head;
    ListNode pre = null;
    while (fast != null) {
        pre = slow;
        slow = slow.next;
        fast = fast.next;
        if (fast != null) fast = fast.next;
    }
    pre.next = null;
    return this.merge(this.sortList(head), this.sortList(slow));
}

private ListNode merge(ListNode first, ListNode second) {
    ListNode head = new ListNode(0), current = head;
    while (first != null && second != null) {
        if (first.val < second.val) {
            current.next = first;
            first = first.next;
        } else {
            current.next = second;
            second = second.next;
        }
        current = current.next;
    }
    if (first != null) current.next = first;
    else current.next = second;
    return head.next;
}