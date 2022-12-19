### 解题思路
首先我们需要有一个快指针，一个慢指针，然后当快指针达到循环的重点的时候，慢指针就找到了中间节点，然后我们把中间节点往后的节点反转，然后在进行前后的判断

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
public static boolean isPalindrome(ListNode head) {
		if (head == null || head.next == null) {
			return true;
		}
		ListNode n1 = head;
		ListNode n2 = head;
		while(n2.next != null && n2.next.next != null) {
			//找中间节点
			n1 = n1.next;
			n2 = n2.next.next;
		}
		n2 = n1.next;
		n1.next = null;
		ListNode n3 = null;
		while(n2 != null) {
			n3 = n2.next;
			n2.next = n1;
			n1 = n2;
			n2 = n3;
		}
		n3 = n1;//指向了右边的头
		n2 = head;
		boolean res = true;
		while(n1 != null && n2 != null) {
			if(n1.val != n2.val) {
				res = false;
				break;
			}
			n1 = n1.next;
			n2 = n2.next;
		}
		
		return res;
	}
        
}
```