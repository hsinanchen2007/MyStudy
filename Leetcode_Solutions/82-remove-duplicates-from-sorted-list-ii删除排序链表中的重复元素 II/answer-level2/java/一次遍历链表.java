### 解题思路
- 每次访问某个节点，遍历下去知道找到大于它的节点，根据数量判断是否有重复

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
    public ListNode deleteDuplicates(ListNode head) {
     if (head == null || head.next == null)
			return head;
		ListNode dummyHead = new ListNode(0);
		dummyHead.next = head;
		ListNode pre = dummyHead;
		ListNode cur = head;
		while (cur != null) {
			ListNode iter = cur;
			int count = 0;
			while (iter.next != null && iter.next.val == cur.val) {
				count++;
				iter = iter.next;
			}
			if (count != 0) {
				pre.next = iter.next;
				cur = pre.next;
			} else {
				pre = cur;
				cur = cur.next;
			}
		}
		return dummyHead.next;
    }
}
```