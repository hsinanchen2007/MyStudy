public ListNode reverseKGroup(ListNode head, int k) {
        if (head == null) {
            return head;
        }
        ListNode good = head;
        int count = 0;
        while (good != null) {
            count++;
            if (count == k) {
                break;
            }
            good = good.next;
        }
        if (count != k) {
            return head;
        }
        ListNode prel = null;
        ListNode next = head.next;
        ListNode ever = head;
        int i= 1;
        while (head != null && i <= k) {
            next = head.next;
            head.next =  prel;
            prel = head;
            head = next;
            i++;
        }
        ever.next = reverseKGroup(head,k);
        return prel;
    }