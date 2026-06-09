```
class Solution {
    public ListNode swapPairs(ListNode head) {
        if(head==null || head.next==null) return head;
        ListNode p=head,q=head.next,out=q;
        while(p!= null && q!=null){
            ListNode m=p;
            p.next=q.next;
            q.next=p;
            p=p.next;
            if(p != null){
             q=p.next;
             m.next=(q==null)?p:q;
            }
        }
        return out;
    }
}
```
