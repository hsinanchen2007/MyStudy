    
    class Solution {
        public ListNode reverseKGroup(ListNode head, int k) {
            if(head == null || head.next == null || k == 1) {
                return head;
            }
            ListNode dummy = new ListNode(-1);
            dummy.next = head;
            int count = 1;
            ListNode p = head, q = head, pre = dummy;
            while(q != null) {
                q = q.next;
                count++;
                if(q != null && count == k) {
                    count = 1;
                    ListNode nextGroup = q.next;
                    while(p != q) {
                        ListNode temp = p;
                        p = p.next;
                        pre.next = p;
                        temp.next = q.next;
                        q.next = temp;
                    }
                    while(p.next != nextGroup) {
                        p = p.next;
                    }
                    pre = p;
                    p = nextGroup;
                    q = nextGroup;
                }
            }
            return dummy.next;
        }
    }