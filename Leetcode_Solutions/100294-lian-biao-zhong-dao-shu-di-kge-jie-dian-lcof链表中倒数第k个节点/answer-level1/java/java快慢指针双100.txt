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
    public ListNode getKthFromEnd(ListNode head, int k) {
        
		if (head == null)
			return null;
		ListNode fast = head;
		ListNode slow = new ListNode(0);
		slow.next = head;
		int count = 0;
		while (fast != null) {
			if (count >= k) {
				slow = slow.next;
			}
			fast = fast.next;
			count++;

		}
		return slow.next;
    }
}
```