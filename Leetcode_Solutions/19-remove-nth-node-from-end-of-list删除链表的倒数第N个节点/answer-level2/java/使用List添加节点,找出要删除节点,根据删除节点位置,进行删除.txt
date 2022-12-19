### 解题思路
此处撰写解题思路

### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
	    	ListNode curr=head;
	        List<ListNode> list = new ArrayList<>();
	    	while(curr!=null) {
	    		list.add(curr);
	    		curr=curr.next;
	    	}
	    	int index = list.size()-n;
	    	if(index==0) {
	    		return head.next;
	    	}else {
	    	    ListNode removedNode = list.get(index);
	    	    if(removedNode.next!=null) {
	    		   removedNode.val=removedNode.next.val;
	    		   removedNode.next=removedNode.next.next;
	    	    }else {
	    	    	ListNode preNode = list.get(index-1);
	    	    	preNode.next=null;
	    	    }
	    	    return head;
	    	}
    }
}
```