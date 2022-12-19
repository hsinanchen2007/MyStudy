class Solution {
   public ListNode partition(ListNode head, int x) {
        ListNode head1=null;
        ListNode end1=null;
        
        boolean ishead1=true;
        ListNode head2=null;
        ListNode end2=null;
        boolean ishead2=true;
        while (head!=null){
            if(head.val<x){
                if(ishead1){
                    head1=head;
                    ishead1=false;
                    end1=head1;
                }
                else {
                    end1.next=head;
                    end1=end1.next;
                    
                }
                head=head.next;
            }
            else 
            {
                if(ishead2){
                    head2=head;
                    ishead2=false;
                    end2=head2;
                }
                else {
                    end2.next=head;
                    end2=end2.next;
                }
                head=head.next;
            }
        }
        end1.next=head2;
        end2.next=null;
        return head1;
    }
}