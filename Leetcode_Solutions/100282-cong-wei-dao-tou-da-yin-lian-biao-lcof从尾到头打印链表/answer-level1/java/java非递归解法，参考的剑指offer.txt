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
    public int[] reversePrint(ListNode head) {
        Stack stack=new Stack();
        int cnt=0;
        while(head!=null){
            cnt++;
            stack.push(head);
            head=head.next;
        }
        int[]res=new int[cnt];
        int i=0;
        while(!stack.empty()){
            ListNode temp=(ListNode)stack.pop();
            res[i++]=temp.val;
        }
        return res;
    }
}
```
