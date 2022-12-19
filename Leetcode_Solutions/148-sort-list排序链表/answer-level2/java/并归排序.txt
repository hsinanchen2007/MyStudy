### 解题思路
由于链表不适合索引、交换等操作，故使用并归排序。

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
    public ListNode sortList(ListNode head) {
        if(head == null || head.next == null) {
        	return head;
        }
        ListNode fast = head;
        ListNode slow = head;
        while(fast.next != null && fast.next.next != null) {
        	slow = slow.next;
        	fast = fast.next.next;
        }
        ListNode head1 = head;
        ListNode head2 = slow.next;
        slow.next = null;
        head1 = sortList(head1);
        head2 = sortList(head2);
        ListNode dummyHead = new ListNode(0);
        ListNode p3 = dummyHead;
        while(head1 != null || head2 != null) {
        	if(head1 == null) {
        		p3.next = head2;
        		break;
        	}
        	if(head2 == null) {
        		p3.next = head1;
        		break;
        	}
        	if(head1.val < head2.val) {
        		p3.next = head1;
        		p3 = p3.next;
        		head1 = head1.next;
        	}
        	else {
        		p3.next = head2;
        		p3 = p3.next;
        		head2 = head2.next;
        	}
        }
        return dummyHead.next;
    }
}
```