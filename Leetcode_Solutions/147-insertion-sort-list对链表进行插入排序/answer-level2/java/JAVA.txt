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
    public ListNode insertionSortList(ListNode head) {
        if(head==null || head.next==null){
            return head; 
        }
        ListNode dummy = new ListNode(-1);
        ListNode pre = head;
        ListNode node = head.next;
        dummy.next = head;
        while(node!=null){
            if(node.val < pre.val){
                ListNode temp = dummy;
                while(temp.next.val < node.val){
                     temp = temp.next;   
                }
                pre.next = node.next;
                node.next = temp.next;
                temp.next = node; 
                node = pre.next;
            }else{
                pre = pre.next;
                node = node.next;
            }
        }
        return dummy.next; 
    }


```
