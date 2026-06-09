### 解题思路
此处撰写解题思路
笨方法但是总算解决了

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
    public ListNode insertionSortList(ListNode head) {
      if(head==null||head.next==null)
		 return head;
	 ListNode start = new ListNode(-1);
	 ListNode first = start;
	 first.next = head;
	 ListNode cur = head.next;
	 while(cur!=null) {
		 ListNode end = head;
		 ListNode tmp = cur.next;
		//System.out.println(cur.val);
		 while(end.next!=cur) {
			 end = end.next;
		 }
		 while(cur.val>head.val&&head.next!=cur) {
			 head = head.next;
			 first = first.next;
		 }
		 if(cur.val<=head.val) {
			 first.next = cur;
			 cur.next = head;
			 end.next = tmp;
		 }
			 head = start.next;
			 first = start;
			 cur = tmp;
		 
	 }
	return start.next;
    }
}
```