### 解题思路
此处撰写解题思路
递归解法

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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
 ListNode result = new ListNode(0);
		 if(l1 == null && l2 == null) {
			 return null;
		 }
		 if(l1 == null) {
			 return l2;
		 }
		 if(l2 == null) {
			 return l1;
		 }
		 ListNode next1 = null;
		 ListNode next2 = null;
		 if(l1.val >= l2.val) {
			 next2 = l2.next;
			 next1 = l1;
			 l2.next = mergeTwoLists(next1,next2);
			 result = l2;
		 }else {
			 next2 = l2;
			 next1 = l1.next;
			 l1.next = mergeTwoLists(next1,next2);
			 result = l1;
		 }
		 return result;
	 }
    

}
```