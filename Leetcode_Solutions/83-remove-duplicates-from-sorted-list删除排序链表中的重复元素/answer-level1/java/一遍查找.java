```
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
      	if(head==null) return head;
        if(head.next==null) return head;
      	ListNode orhead=head;
      	ListNode dup=head;
      	while(dup.next!=null) {
      		if(dup.next.val==dup.val) dup=dup.next;
      		else {
      			dup=dup.next;
      			head.next=dup;
      			head=dup;
      		}
      	}
        head.next=null;
      	return orhead;       
    }
}
```
