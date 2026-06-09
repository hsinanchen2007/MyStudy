/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
   public ListNode swapPairs(ListNode head) {
        ListNode begin=head;
        ListNode left=null;
        ListNode right=null;
        boolean ishead=true;
        while (begin!=null){
            if(ishead){
                left=head;
                right=head.next;
                if(right==null){
                    return head;
                }
                begin=right.next;
                if(right.next==null||right.next.next==null){
                    left.next=right.next;
                }
                
                else{
                left.next=right.next.next;
                }
                right.next=left;
                head=right;

                ishead=!ishead;
            }
            else {
                left=begin;
                if(begin.next==null){

                    return head;
                }
                right=begin.next;
                begin=right.next;
                 if(right.next==null||right.next.next==null){
                    left.next=right.next;
                }
                
                else{
                    left.next=right.next.next;
                }
                right.next=left;

            }
        }
        return head;
    }
}