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
        ListNode dummyHead = new ListNode(0);
        dummyHead.next = head;
        ListNode prev = dummyHead;
        while(prev.next != null){
            if(prev.next.val == val){
                break;
            }
            prev = prev.next;
        }
        ListNode del = new ListNode(0);
        del = prev.next;
        prev.next = del.next;
        del.next = null;
        //这里注意，返回值不能写head,如果写head的话，删除的元素恰好是头节点会发生错误
        return dummyHead.next;
    }
}