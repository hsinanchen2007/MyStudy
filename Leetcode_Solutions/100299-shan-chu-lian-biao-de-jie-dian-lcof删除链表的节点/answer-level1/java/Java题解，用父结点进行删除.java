/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode deleteNode(ListNode head, int val) {
        ListNode cur = head;
        if(cur == null) return head;
        if(cur.val == val){
            return cur.next;
        }
        while(cur.next!=null){
            if(cur.next.val==val){
                cur.next=cur.next.next;
                return head;
            }
            cur=cur.next;
        }
        return head;
    }
}