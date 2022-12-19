```
class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        ListNode pre=new ListNode(0);
        pre.next=head;
        int cnt=1;
        ListNode prehead=pre;
        while(cnt<m){
            head=head.next;
            prehead=prehead.next;
            cnt++;
        }
        while(cnt<n){
            ListNode next=head.next;
            head.next=next.next;
            next.next=prehead.next;
            prehead.next=next;
            cnt++;
        }
        return pre.next;
    }
}
```
