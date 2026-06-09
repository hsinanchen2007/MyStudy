/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode quick = head;
        ListNode slow = head;
        int count = 0;
        while (quick != null) {
            if (count > n) {
                slow = slow.next;
            }
            quick = quick.next;
            count++;
        }
        if(count == n) {
            return head.next;
        }
        slow.next = slow.next.next;
        return head;
    }
}