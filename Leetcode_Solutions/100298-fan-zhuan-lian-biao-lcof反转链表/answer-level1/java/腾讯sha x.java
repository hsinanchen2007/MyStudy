### 解题思路
dummy node + 插头法

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
    public ListNode reverseList(ListNode head) {
        if(head==null || head.next == null)
            return head ;
        ListNode dummy = new ListNode(-1) ;
        dummy.next = head ;
        ListNode curNode = head.next ;
        ListNode preNode = head ;
        while(curNode != null) {

            preNode.next = curNode.next ;
            curNode.next = dummy.next ;
            dummy.next = curNode ;

            curNode = preNode.next ;
        }
        preNode.next = null ;
        return dummy.next ;
    }
}
```