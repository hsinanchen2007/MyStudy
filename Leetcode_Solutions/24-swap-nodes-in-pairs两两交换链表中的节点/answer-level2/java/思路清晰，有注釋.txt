### 解题思路
*有注釋*

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
    public ListNode swapPairs(ListNode head) {
       ListNode dummyHead = new ListNode(0);
		dummyHead.next = head;
		ListNode pre = dummyHead;
		while (pre.next != null && pre.next.next != null) {
			//保存前面的节点
			ListNode before = pre.next;
			//保存后面的节点
			ListNode behind = pre.next.next;
			//前面节点next指向后面节点next
			before.next=behind.next;
			//后面节点next指向前面节点
			behind.next=before;
			//pre节点next指向behind
			pre.next=behind;
			pre = before;
		}
		return dummyHead.next;

    }
}
```