class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode head1=l1;
        ListNode head2=l2;
        ListNode head3 = new ListNode(-1);
        ListNode l3;
        l3=head3;
        while(head1!= null && head2!=null){
             if(head1.val >= head2.val){
                 head3.next = head2;
                 head2=head2.next;
             }
             else {
                 head3.next = head1;
                 head1=head1.next;
            }
            head3=head3.next;//***
        }
        if(head1!=null){
            head3.next=head1;
        }
        if(head2!=null){
            head3.next=head2; 
        }    
    return l3.next;
    }
}