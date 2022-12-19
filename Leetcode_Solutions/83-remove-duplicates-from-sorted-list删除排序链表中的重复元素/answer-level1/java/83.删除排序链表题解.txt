
```
class Solution{
	public ListNode deleteDuplicates(ListNode head){
		ListNode newHaed=head;
		ListNode temp=head;
		while(head!=null){
			if(temp.val!=head.val){
				temp.next=head;
				temp=temp.next;
			}
			head=head.next;
			temp.next=null;
		}
		return newHaed;
	}
}
```