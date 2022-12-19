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
        if(head == null || head.next == null) {
            return head;
        }
        
        ListNode preHead = new ListNode(-1);
        preHead.next = head;
        ListNode p = preHead;
        
        boolean flag = false;
        while (p.next.next != null) {
            if (p.next.val == p.next.next.val) {
                p.next.next = p.next.next.next;
                flag = true;
            } else {
                if (flag) {
                    p.next = p.next.next;
                    flag = false;
                } else {
                    p = p.next;
                }
            }
        }
        
        if (flag) {
            p.next = p.next.next;
        }
        
        return preHead.next;
    }
}
```
