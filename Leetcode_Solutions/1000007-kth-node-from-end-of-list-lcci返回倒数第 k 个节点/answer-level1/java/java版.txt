    class Solution {
        public int kthToLast(ListNode head, int k) {
            ListNode fast=head;
            ListNode slow=head;
            while(fast!=null){
                fast=fast.next;
                if(k>0){
                    k--;
                }else{
                     slow=slow.next;
                }
            }
            return slow.val;
        }
    }