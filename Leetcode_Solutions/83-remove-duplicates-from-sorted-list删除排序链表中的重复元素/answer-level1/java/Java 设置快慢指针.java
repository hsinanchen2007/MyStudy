### 解题思路
快指针会跳过连续重复的元素，直到一个不重复的元素，将慢指针的next指向快指针，快指针继续遍历直到链表最后，指向null。

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
        ListNode slowNode = head;
		
		while(slowNode!= null) {
			 ListNode fastNode = slowNode.next;
			 while(fastNode != null && fastNode.val == slowNode.val )           {
				 fastNode = fastNode.next;
			 }
			 slowNode.next = fastNode;
			 slowNode = slowNode.next;
		}
		
		return head;
    }
}
```