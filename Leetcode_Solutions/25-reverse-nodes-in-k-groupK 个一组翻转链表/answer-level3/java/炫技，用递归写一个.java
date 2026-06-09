    
    class Solution {
        public ListNode reverseKGroup(ListNode head, int k) {
            if(head == null || head.next == null || k == 1) {
                return head;
            }
            int count = 1;
            ListNode p = head, q = head;
            while(count < k && q != null) {
                count++;
                q = q.next;
            }
            if(count == k && q != null) {
                q.next = reverseKGroup(q.next, k);
                //将p与q之间的node反转
                while(p != q) {
                    ListNode temp = p;
                    p = p.next;
                    temp.next = q.next;
                    q.next = temp;
                }
                return q;
            }else {
                return head;
            }
        }
    }