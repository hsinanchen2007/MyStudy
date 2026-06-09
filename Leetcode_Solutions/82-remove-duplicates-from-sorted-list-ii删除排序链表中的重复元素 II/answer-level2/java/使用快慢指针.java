### 解题思路
使用快慢指针

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
        ListNode dummy=new ListNode(0);
        dummy.next=head;
        ListNode preNode=dummy;
        ListNode curNode=dummy.next;
        int count=1;
        while(curNode!=null) {
        	while(curNode.next!=null&&curNode.val==curNode.next.val) {
        		count++;
        		curNode=curNode.next;
        	}
        	if(count>=2) {
        		ListNode tempNode=curNode.next;
        		preNode.next=tempNode;
        		curNode=tempNode;
        	}else {
        		preNode=preNode.next;
        		curNode=curNode.next;
        	}
        	count=1;
        }
        return dummy.next;
    }
}
```