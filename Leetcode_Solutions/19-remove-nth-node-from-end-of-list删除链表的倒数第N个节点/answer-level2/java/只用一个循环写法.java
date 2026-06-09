### 解题思路
官方一次循环答案里用了一个for循环和一个while循环，虽然实际上只循环链表了一次，但看上去给人了一种误解。

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
    	int i=1;
		int j=1;
		ListNode head0=head;
		ListNode head1=head;
		while(head0!=null) {
			if(head0.next==null) {
				if(i-j==n) {
					head1.next=head1.next.next;
				}else {
					head=head.next;
				}
				
				return head;
			}
			if(i-j==n) {
				j++;
				head1=head1.next;
				
			}
			i++;
			head0=head0.next;
		}
		
		
		return null;
    }
}
```