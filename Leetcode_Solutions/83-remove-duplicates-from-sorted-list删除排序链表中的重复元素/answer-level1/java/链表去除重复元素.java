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
    public ListNode deleteDuplicates(ListNode head) {

		if(head == null || head.next == null)
			return head;
		
		ListNode point = head; 
		
		while(point.next != null){
			if(point.val == point.next.val) 
				point.next = point.next.next;
			else{
				point = point.next;
			}
		}
		return head;
    }
}
```