class Solution {
    public ListNode getKthFromEnd(ListNode head, int k) {
        if(head == null || head.next == null) return head;
        if(k <= 0) return null;
        ListNode pre=head,endk=head;
        int index = 1;
        while(endk.next!=null && index<k) {
        	endk = endk.next;
        	index++;
        }
        while(endk.next!=null) {
        	pre = pre.next;
        	endk = endk.next;
        }
        return pre;
    }
}