### 解题思路
最简单的数据结构题
执行用时 :
0 ms
, 在所有 Java 提交中击败了
100.00%
的用户
内存消耗 :
39.1 MB
, 在所有 Java 提交中击败了
100.00%
的用户

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
    public ListNode deleteNode(ListNode head, int val) {
    	ListNode temp = head;
    	if(temp.val==val) temp=temp.next;
    	while(head.next!=null) {
    		if(head.next.val==val) {
        		head.next=head.next.next;
        		break;
        	}
    		head = head.next;
    	}
    	
    	return temp;
    }
}
```