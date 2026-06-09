/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode test = new ListNode(0);
        ListNode result = test;

        while (l1 != null && l2 != null){
            if(l1.val <= l2.val){
                test.next = new ListNode(l1.val);
                l1 = l1.next;
            }else {
                test.next = new ListNode(l2.val);
                l2 = l2.next;
            }
            test = test.next;
        }
        while (l1 != null){
            test.next = new ListNode(l1.val);
            l1 = l1.next;
            test = test.next;
        }
        while (l2 != null){
            test.next = new ListNode(l2.val);
            l2 = l2.next;
            test = test.next;
        }

        return result.next;
    }
}