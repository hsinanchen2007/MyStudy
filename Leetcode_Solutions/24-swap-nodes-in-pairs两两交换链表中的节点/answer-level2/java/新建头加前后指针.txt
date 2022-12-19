```
class Solution {
    public ListNode swapPairs(ListNode head) {
        if(head==null){
            return null;
        }
        ListNode tmp=new ListNode(-1);
        ListNode res=null;
        ListNode p1=head;
        ListNode p2=head.next;
        if(p2!=null){
            res=p2;
        }else{
            res=p1;
        }
          
        while(p2!=null){
            tmp.next=p2;
            ListNode other=p1;
            p1=p2.next;
            p2.next=other;
            
            tmp=tmp.next.next;
            
            if(p1!=null){
                p2=p1.next;
            }else{
                other.next=null;
                break; 
            }
        }
        if(p1!=null){
            tmp.next=p1;
        }
        return res;

    }
}
```
