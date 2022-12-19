![2019123102.PNG](https://pic.leetcode-cn.com/668ddb52333a15e88a2ff5072de0b4838d3c24d6f5f04c48760b1f0cd661ceb0-2019123102.PNG)
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
    public ListNode removeElements(ListNode head, int val) {
    	ListNode p=head;
    	while(p!=null&&p.next!=null) {
        	if(p.val==val) {
        		head = p.next;
        		p=head;
        	}else if(p.val!=val) {
        		if(p.next.val==val) {
        			p.next=p.next.next;
        		}else if(p.next.val!=val) {
        			p =p.next;
        		}
        	}
    	}
    	if(p!=null&&p.next==null) {
    		if(p.val==val) {
        		head = null;
        	}
    	}
    	return head;
    }
}
```