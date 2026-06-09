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
    public ListNode rotateRight(ListNode head, int k) {
        if(k<=0||head==null||head.next==null){
            return head;
        }
        
        int nodecount = 0;
        ListNode curr = head;
        while(curr!=null){
            curr=curr.next;
            nodecount++;
        }
        
        ListNode first  = head;
        ListNode second = head;
        
        int firstSteps = k%nodecount;
        if(firstSteps==0){
            return head;
        }
        while(firstSteps>0){
            first = first.next;
            firstSteps--;
        }
        
        ListNode lastAfterRotate = null;
        while(first!=null){
            first=first.next;
            lastAfterRotate = second;
            second = second.next;
        }
        lastAfterRotate.next=null;
        ListNode result = second;
        while(second.next!=null){
            second=second.next;
        }
        second.next = head;
        
        return result;
        
        
    }
}
```
