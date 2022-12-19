### 解题思路
## 找到m节点的父节点，记录下来，从m节点开始迭代，迭代次数为n-m+1，然后拼接起来两边

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
    public ListNode reverseBetween(ListNode head, int m, int n) {
      	if (head == null || m >= n)
			return head;
		ListNode pre = new ListNode(0);
		pre.next = head;
		ListNode left = pre;
		for (int i = 0; i < m - 1; i++) {
			left = left.next;
		}
		int k = n - m + 1;
		// cur为m节点
		ListNode cur = left.next;
		ListNode front = null;
		while (k > 0) {
			// 当前迭代节点的next节点
			ListNode tmp = cur.next;
			// 让当前节点指向当前next
			cur.next = front;
			// 更新next节点
			front = cur;
			// 更新迭代节点
			cur = tmp;
			// 减少迭代次数
			k--;
		}
		left.next.next = cur;
		left.next = front;
		return pre.next;
    }
}
```