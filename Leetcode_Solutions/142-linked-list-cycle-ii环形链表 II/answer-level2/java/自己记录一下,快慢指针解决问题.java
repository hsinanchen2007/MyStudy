/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
 //定义一个快指针一个走两步,定义一个慢指针一次走一步,如果链表有环,那么快慢指针最后一定能相遇
 //当一个指针需要一次走两步时,不能一次走两步,需要一次一次的走,因为如果第一步后就是空节点,就不能再走第二步了.
public class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode slow=head;
        ListNode quick=head;
        ListNode meet=null;
        while(quick!=null){
            slow=slow.next;
            quick=quick.next;
                if(quick==null){
                    return null;
                }
                else{
                    quick=quick.next;
                }
            if(quick==slow){
                meet=quick;
                break;
            }
        }
        if(meet==null){
            return null;
        }
        if(meet==head){
            return head;

        }
        else{
            while(head!=meet){
                head=head.next;
                meet=meet.next;
            }
            return meet;
        }

    }
}