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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode(-1);
		dummy.next = head;
		
		ListNode p = head;
		
		int len = 0;
		while(head != null) { //1(head)->2->3->4->5
			len ++;
			head = head.next;
		}
		
		int cur = 0;
		p = dummy;
		while(cur < (len - n)) {
			p = p.next;
			cur ++;
		}
		p.next = p.next.next;
		
		return dummy.next;
    }
}
```
![image.png](https://pic.leetcode-cn.com/cff35dc159d0293b9c7024632593eb7e3463022078875608096a0ed6052197b1-image.png)
