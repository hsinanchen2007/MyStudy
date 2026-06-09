### 解题思路
## 买不起哨兵

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
    public ListNode partition(ListNode head, int x) {
		// 当前小于x链表的最后一个节点
		ListNode p = null;
		// 当前大于等于x链表的最后一个节点；
		ListNode q = null;
		// 小于x链表的第一个节点
		ListNode ps = null;
		// 大于等于x链表的第一个节点
		ListNode qs = null;
		// 迭代节点
		ListNode iter = head;
		while (iter != null) {
			if (iter.val < x) {
				ps = ps == null ? iter : ps;
				if (p != null) {
					p.next = iter;
				}
				p = iter;
			} else {
				qs = qs == null ? iter : qs;
				if (q != null) {
					q.next = iter;
				}
				q = iter;
			}
			iter = iter.next;
		}
		if (qs != null) {
			q.next = null;
			if (ps != null) {
				p.next = qs;
				head = ps;
			} else {
				head = qs;
			}
		} else {
			head = ps;
		}
		return head;
    }
}
```