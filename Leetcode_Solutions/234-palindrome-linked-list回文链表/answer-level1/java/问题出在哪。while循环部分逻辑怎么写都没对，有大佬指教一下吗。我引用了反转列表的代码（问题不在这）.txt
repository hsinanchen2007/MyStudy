/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isPalindrome(ListNode head) {
        if(head==null) return true;
        ListNode turnhead = reverseList(head);
        while(head!=null){
            if(head!=turnhead){
                return false;
            }
            head = head.next;
            turnhead = turnhead.next;
        }
        return true;
    }
    public ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode curr = head;
        while(curr!=null){
            ListNode Tempnext = curr.next;
            curr.next =prev;
            prev = curr;
            curr = Tempnext;
        }
        return prev;
    }
}