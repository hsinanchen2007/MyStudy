### 解题思路
## 买一送一

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
		ListNode pre = new ListNode(0);
		ListNode res = pre;
		while (l1 != null && l2 != null) {
			if (l1.val > l2.val) {
				pre.next = l2;
				pre = pre.next;
				l2=l2.next;
			} else {
				pre.next = l1;
				pre = pre.next;
				l1=l1.next;
			}
		}
		if (l1 != null) {
			pre.next = l1;
		}
		if (l2 != null) {
			pre.next = l2;
		}
		return res.next;
    }
}
```