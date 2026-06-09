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
    public void reorderList(ListNode head) {
        if(head==null||head.next==null) return;
        if(head.next.next==null) return;

        Stack<ListNode> stack = new Stack<ListNode>();
        ListNode p1 = head;
        ListNode p2 = head;
        while(p1!=null){
            stack.push(p1);
            p1 = p1.next;
        }
        int size = stack.size();
        
        while(p2!=null){
            ListNode next = p2.next;
            ListNode newNode = stack.pop();
            p2.next = newNode;
            newNode.next = next;
            p2 = next;
            if(size%2==0&&stack.size()==(size/2+1)){
                p2.next.next = null;
                break;
            }else if(size%2==1&&stack.size()==(size+1)/2){
                p2.next = null;
                break;
            }
        }
    }
}
```
