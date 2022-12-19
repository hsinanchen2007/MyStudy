```java []
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if(l1==null) return l2;
        if(l2==null) return l1;
        int flag=0;
        int r;
        ListNode pre=new ListNode();
        ListNode p=pre;
        while(l1!=null && l2!=null){
            r=l1.val+l2.val+flag;
            if(r>=10){
                p.next=new ListNode(r-10);
                flag=1;
            }
            else{
                p.next=new ListNode(r);
                flag=0;
            }
            p=p.next;
            l1=l1.next;
            l2=l2.next;
        }
        if(l1==null){
            while(l2!=null){
                r=l2.val+flag;
                if(r>=10){
                    p.next=new ListNode(r-10);
                    flag=1;
                }
                else{
                    p.next=new ListNode(r);
                    flag=0;
                }
                l2=l2.next;p=p.next;
            }
        }
        else{
            while(l1!=null){
                r=l1.val+flag;
                if(r>=10){
                    p.next=new ListNode(r-10);
                    flag=1;
                }
                else{
                    p.next=new ListNode(r);
                    flag=0;
                }
                l1=l1.next;p=p.next;
            }
        }
        if(flag==1) p.next=new ListNode(1);
        return pre.next;
    }
}
```
