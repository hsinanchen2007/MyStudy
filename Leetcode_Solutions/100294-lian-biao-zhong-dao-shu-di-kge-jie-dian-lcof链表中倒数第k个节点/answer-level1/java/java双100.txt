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
    public ListNode getKthFromEnd(ListNode head, int k) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode fir = dummy;
        ListNode sec = dummy;
        for(int i = 0; i <= k; i++) {
            fir = fir.next;
        }
        while(fir != null) {
            fir = fir.next;
            sec = sec.next;
        }
        return sec.next;
    }
}
```
