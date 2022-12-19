### 解题思路
又强化了一次递归思想

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
    public ListNode swapPairs(ListNode head) {
        if(head == null) {
			return null;
		}
        if(head.next == null) {
			return head;
		}
        ListNode next = head.next;
		head.next = swapPairs(next.next);
		next.next = head;
		return next;
    }
}
```