### 解题思路
	(1)两个链表的头元素都是两个数字的最低位。
	(2)整数加法就是从最低位开始的，所以我们也可以从最低位开始加。
	(3)整数加法要注意的是如何解决进位，这里我们定一个pass的整型变量来保存进位。并且初始化进位pass=0;每次进行位加法时就把pass也加上。
	(4)除了解决进位问题，还要解决两个数的位数不等问题，如23+654；我们假设num1为链表一的加数，num2为链表2的加数，当我们遍历链表1和2时，如果发现遍历的节点为空，我们就让num1=0,或num2=0即可。

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
		ListNode head = new ListNode(0);
		ListNode temp = head;
		int pass = 0;
		while (l1 != null || l2 != null) {
			int num1 = 0;
			int num2 = 0;
			if (l1 == null) {
				num1 = 0;
			} else {
				num1 = l1.val;
				l1 = l1.next;
			}
			if (l2 == null) {
				num2 = 0;
			} else {
				num2 = l2.val;
				l2 = l2.next;
			}
			int[] sum = new int[2];
			sum[0] = (num1 + num2+pass) / 10;
			sum[1] = (num1 + num2+pass) % 10;
			ListNode curNode = new ListNode(sum[1]);
			pass = sum[0];
			temp.next = curNode;
			temp = curNode;
		}
		if (pass != 0) {
			ListNode curNode = new ListNode(pass);
			temp.next = curNode;
		}
		return head.next;
	}
}


```