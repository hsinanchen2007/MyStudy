public ListNode deleteNode(ListNode head, int val) {
        ListNode node = new ListNode(0);
        node.next = head;
        ListNode pre = node;
        while (node != null && node.next != null){
            if (node.next.val == val){
                node.next = node.next.next;
            }
            node = node.next;
        }
        return pre.next;
    }
}