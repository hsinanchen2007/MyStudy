```
class Solution {
 public ListNode deleteDuplicates(ListNode head) {
    	if(head == null || head.next == null){
    		return head;
    	}
    	ListNode pre = new ListNode(-1);
    	pre.next = head;
    	ListNode point = head;
    	
    	while(point != null && point.next!=null){
    		if(point.val == point.next.val){
    			point.next = point.next.next;
    		}else{
    			point = point.next;
    		}
    	}
        return pre.next;
    }
}
```

