### 解题思路
我想知道题库中只要提到“有序”是不是都是指的“从小到大”？
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
      ListNode result = null;
		ListNode x = null;
		while (l1 != null || l2 != null) {
			ListNode t = null;
			if (l1 == null) {
				t = l2;
				l2=l2.next;
			} else if (l2 == null) {
				t = l1;
				l1=l1.next;
			} else if (l1.val >= l2.val) {
				t = l2;
				l2 = l2.next;
			} else {
				t = l1;
				l1 = l1.next;
			}
			if (x == null) {
				x = t;
				result = t;
			} else {
				x.next = t;
				x = x.next;
			}
		}
		return result;
    }
}
```