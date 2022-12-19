### 解题思路

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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode dummyHead = new ListNode(0);
    	ListNode curr=dummyHead;
    	while(l1!=null&&l2!=null) {
    		if(l1.val<l2.val) {
    			curr.next=new ListNode(l1.val);
    			l1=l1.next;
    		}else {
    			curr.next=new ListNode(l2.val);
    			l2=l2.next;
    		}
    		curr=curr.next;
    	}
    	while(l1!=null) {
    		curr.next=l1;
    		curr=curr.next;
    		l1=l1.next;
    	}
    	while(l2!=null) {
    		curr.next=l2;
    		curr=curr.next;
    		l2=l2.next;
    	}
    	return dummyHead.next;

    }
}
```