    /**
     * 1. 设置一个虚节点dummy指向头节点
     * 2. 从dummy节点开始 寻找倒数k+1个节点 node(last k+1)
     * 3. (1)如果 node(last k+1) == dummy,要删除的是头节点
     *    (2)否则node(last k+1).next = node(last k+1).next.next
     */
    public ListNode removeNthFromEnd(ListNode head, int k) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode lastKPlus1 = dummy;
        ListNode iter = dummy;
        int num = 0;
        while (num < k+1) {
            iter = iter.next;
            num += 1;
        }

        while (iter != null) {
            iter = iter.next;
            lastKPlus1 = lastKPlus1.next;
        }

        if (lastKPlus1 == dummy) {
            return dummy.next.next;
        } else {
            lastKPlus1.next = lastKPlus1.next.next;
            return head;
        }
    }