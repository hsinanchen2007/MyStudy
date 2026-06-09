class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        if (head == null || head.next == null) {
            return head;     
        }
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        head = dummy;
        while (head != null) {
            head = reverse(head, k);
        }
        return dummy.next;
    }

    private ListNode reverse(ListNode node, int k) {
        ListNode preHead = node;        
        ListNode head = node.next;            
      
        for (int i = 0; i < k; i++) {
            node = node.next;
            if (node == null) {
                return null;
            }
        }
        ListNode tail = node;
        ListNode tailNext = tail.next;

        ListNode pre = null;
        ListNode cur = head;
        while (cur != tailNext) {
            ListNode temp = cur.next;
            cur.next = pre;
            pre = cur;
            cur = temp;
        }

        preHead.next = pre;
        head.next = tailNext;

        return head;

    }
}