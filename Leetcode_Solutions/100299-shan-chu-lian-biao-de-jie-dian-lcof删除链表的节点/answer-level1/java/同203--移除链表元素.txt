```
class Solution {
    public ListNode deleteNode(ListNode head, int val) {
        ListNode thead=new ListNode(0);
        thead.next=head;
        ListNode pre=thead,cur=head;
        while(cur!=null){
            if(cur.val==val){
                pre.next=cur.next;
            }else{
                pre=cur;
            }
            cur=cur.next;
        }
        return thead.next;
    }
}
```
