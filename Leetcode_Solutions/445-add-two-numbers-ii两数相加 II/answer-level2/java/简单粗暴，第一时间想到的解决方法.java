### 解题思路
1.先分别将两个链表翻转
2.在对应相加，同LeetCode题2
3.最后将结果在反转

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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
		if (l1 == null) {
			return l2;
		}
		if (l2 == null) {
			return l1;
		}
		ListNode resp = new ListNode(-1);
		ListNode tmp = resp;
		ListNode reverseNode1 = reverseNodeByLoop(l1);
		ListNode reverseNode2 = reverseNodeByLoop(l2);
		int carry = 0;
		while (reverseNode1 != null || reverseNode2 != null) {
			int val1 = reverseNode1 == null ? 0 : reverseNode1.val;
			int val2 = reverseNode2 == null ? 0 : reverseNode2.val;
			int sum = val1 + val2 + carry;
			tmp.next = new ListNode(sum % 10);
			carry = sum / 10;
			if (reverseNode1 != null) {
				reverseNode1 = reverseNode1.next;
			}
			if (reverseNode2 != null) {
				reverseNode2 = reverseNode2.next;
			}
			tmp = tmp.next;
		}
		if (carry != 0) {
			tmp.next = new ListNode(carry);
		}

		return reverseNodeByLoop(resp.next);
	}

	public ListNode reverseNodeByLoop(ListNode head) {
		ListNode pre = null;
		ListNode cur = head;
		ListNode resp = null;
		while (cur != null) {
			ListNode next = cur.next;
			if (next == null) {
				resp = cur;
			}
			cur.next = pre;
			pre = cur;
			cur = next;
		}
		return resp;
	}
}
```