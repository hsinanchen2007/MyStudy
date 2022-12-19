public class Solution {
    public static ListNode oddEvenList(ListNode head) {
        ListNode before_head=new ListNode(-1);
        ListNode before=before_head;
        ListNode after_head=new ListNode(-1);
        ListNode after=after_head;

        while(head!=null)
        {
            if(head!=null)
            {
                before.next=head;
                before=before.next;
                head=head.next;
            }
            if(head!=null)
            {
                after.next=head;
                after=after.next;
                head=head.next;
            }
        }
        after.next=null;
        before.next=after_head.next;
        return before_head.next;
    }