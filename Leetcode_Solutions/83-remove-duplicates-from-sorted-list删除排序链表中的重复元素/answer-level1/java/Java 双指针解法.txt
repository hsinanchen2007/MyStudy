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
        ListNode worker = head;
        ListNode tmp；

        while (worker != null && worker.next != null) {
            tmp = worker.next;

            while (tmp.val == worker.val && tmp.next != null) {
                tmp = tmp.next;
            }

            if (tmp.val == worker.val) {
                worker.next = null;
            } else {
                worker.next = tmp;
                worker = tmp;
            }
        }

        return head;
    }
}
```
