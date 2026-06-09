```
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
        if ( head == null || head.next == null ) {
            return head;
        }
        ListNode pre = new ListNode(0);
        ListNode q = pre;
        pre.next = head;
        ListNode cur = head;
        while ( cur != null && cur.next != null) {
            if ( cur.val == cur.next.val ) {
                int x = cur.val;
                while ( cur.next != null && cur.next.val == x ) {
                    cur = cur.next;
                }
                cur = cur.next;
                q.next = cur;
            }
            else {
                cur = cur.next;
                q = q.next;
            }
        }
        return pre.next;
    }
}
```
