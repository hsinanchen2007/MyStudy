```
class Solution {
    public ListNode reverseList(ListNode head) {
		if(head==null)
			return head;
        ListNode l=new ListNode(head.val);
        while(head.next!=null) {
        	ListNode n=new ListNode(head.next.val);
        	n.next=l;
        	l=n;
        	head=head.next;
        }
        return l;
    }
}
```
```
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head == None or head.next == None:
            return head
        ln = ListNode(head.val)
        head = head.next
        while head != None:
            temp = ListNode(head.val)
            temp.next = ln
            ln = temp
            head = head.next
        return ln
```



