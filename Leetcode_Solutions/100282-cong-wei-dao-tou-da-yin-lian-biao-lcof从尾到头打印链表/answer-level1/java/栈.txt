### 代码

```java
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
        if(head == null) return new int[0];
        Stack<ListNode> stack = new Stack<>();
        while(head != null){
            stack.push(head);
            head = head.next;
        }
        int[] res = new int[stack.size()];
        int count = 0;
        while(!stack.isEmpty()){
            res[count++] = stack.pop().val;
        }
        return res;
    }
}
```