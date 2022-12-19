    public ListNode detectCycle(ListNode head) {
        if (head == null) {
            return null;
        }
        while (head != null) {
            if (head.val == Integer.MIN_VALUE) {
                return head;
            }
            head.val = Integer.MIN_VALUE;
            head = head.next;
        }
        return null;
    }
有点瑕疵的100%，无任何额外空间。