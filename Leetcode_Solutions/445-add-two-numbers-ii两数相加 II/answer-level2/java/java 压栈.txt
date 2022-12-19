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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if(l1==null){
            return l2;
        }
        if(l2==null){
            return l1;
        }

        Stack<Integer> l1s = new Stack<>();
        Stack<Integer> l2s = new Stack<>();

        ListNode t1=l1;
        while(t1!=null){
            l1s.push(t1.val);
            t1=t1.next;
        }
        t1 = l2;
        while(t1!=null){
            l2s.push(t1.val);
            t1=t1.next;
        }
        int carryover = 0;
        ListNode head = null;
        while(!l1s.isEmpty()||!l2s.isEmpty()){
            int val1 = l1s.isEmpty()?0:l1s.pop();
            int val2 = l2s.isEmpty()?0:l2s.pop();
            int sum = val1+val2+carryover;
            if(sum>9){
                carryover=1;
            }else{
                carryover=0;
            }
            ListNode temp = new ListNode(sum%10);
            temp.next = head;
            head = temp;
        }
        if(carryover==1){
            ListNode temp = new ListNode(1);
            temp.next = head;
            head = temp;
        }
        return head;

            
    }
}
```
