### 解题思路
此处撰写解题思路

### 代码

```java
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        
		if (head == null || head.next == null) return false;
		
		ListNode slow = head.next;
		ListNode fast = head.next.next;
		while (fast != slow) {
			if (fast == null || fast.next == null) return false;
			slow = slow.next;
			fast = fast.next.next;
		}
		
		return true;
	

	
    }
}
```