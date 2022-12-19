    // 小于链表 + 大于等于链表
    class Solution {
        public ListNode partition(ListNode head, int x) {
            ListNode p = head, q = head;
            while(q != null) {
                if(q.val < x) {
                    int temp = p.val;
                    p.val = q.val;
                    q.val = temp;
                    p = p.next;
                    q = q.next;
                }else {
                    q = q.next;
                }
            }
            return head;
        }
    }