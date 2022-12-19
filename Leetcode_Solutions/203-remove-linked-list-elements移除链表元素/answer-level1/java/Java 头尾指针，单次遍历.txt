``` java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

class Solution {
    public ListNode removeElements(ListNode head, int val) {
        ListNode newHead = new ListNode(-1);
        ListNode newTail = newHead;

        while (head != null) {
            if (head.val != val) {
                newTail.next = head;
                newTail = newTail.next;
            }

            head = head.next;
            newTail.next = null;
        }

        if (newHead.next != null) {
            newHead = newHead.next;
        } else {
            newHead = null;
        }

        return newHead;
    }
}
```
