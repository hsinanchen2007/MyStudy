// #### 时隔一年，回头写一遍，为了不new节点直接在原链表上改的，结果发现耗时差不多的 🤣

// ```dart
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummyNode=new ListNode(-1);
        dummyNode.next=l1;
        int carry=0;
        ListNode last=l1;
        while(l1!=null && l2!=null){
            int sum= l1.val + l2.val+ carry;
            l1.val=sum%10;
            carry=sum/10;
            last=l1;
            l1=l1.next;
            l2=l2.next;
        }
        while(l1!=null && carry!=0){
            int sum = l1.val + carry;
            l1.val=sum%10;
            carry=sum/10;
            last=l1;
            l1=l1.next;
        }
        if(l2!=null){
            last.next=l2;
            while(l2!=null && carry!=0){
                int sum = l2.val + carry;
                l2.val=sum%10;
                carry=sum/10;
                last=l2;
                l2=l2.next;
            }
        }
        if(carry!=0) last.next=new ListNode(1);
        return dummyNode.next;
    }
}
// ```
