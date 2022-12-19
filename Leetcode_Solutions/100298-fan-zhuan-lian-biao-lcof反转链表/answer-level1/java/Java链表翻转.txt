```
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode newhead=null;
        while(head!=null){
            ListNode tmp=head.next;
            head.next=newhead;
            newhead=head;
            head=tmp;
        }
        return newhead;
    }
}
```
