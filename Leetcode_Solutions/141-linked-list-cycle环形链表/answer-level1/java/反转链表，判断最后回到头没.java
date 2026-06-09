public class Solution {
    public boolean hasCycle(ListNode head) {
        if(head==null || head.next==null)return false;
        ListNode p=head;
        ListNode q=null;
        ListNode s=null;
        while(p!=null){
            s=p.next;
            p.next=q;
            q=p;
            p=s;
        }
        if(q!=head)return false;
            else return true;
    }
}