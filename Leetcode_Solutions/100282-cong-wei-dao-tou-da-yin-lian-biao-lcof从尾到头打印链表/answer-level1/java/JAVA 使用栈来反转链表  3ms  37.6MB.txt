因为给出得链表是单向得，所以我就使用了栈来暂存一下取出来得节点，这样就可以保证反序了

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
        Stack<Integer> stack = new Stack<>();
        while(head!=null){
            stack.add(head.val);
            head = head.next;
        }
        int[] res = new int[stack.size()];
        int i =0;
        while(!stack.isEmpty()){
            res[i++]=stack.pop();
        }
        return res;    
    }
}
```