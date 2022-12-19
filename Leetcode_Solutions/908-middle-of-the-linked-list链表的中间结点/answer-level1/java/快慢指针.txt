### 解题思路
如下

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
    public ListNode middleNode(ListNode head) {
    	ListNode fast=head, low=head;
    	while (fast!=null&&low!=null&&fast.next!=null) {
			low=low.next;
    		fast=fast.next.next;    //快指针q每次走2步，慢指针p每次走1步，当q走到末尾时p正好走到中间。
		}
		return low;
    	

    }
}
```