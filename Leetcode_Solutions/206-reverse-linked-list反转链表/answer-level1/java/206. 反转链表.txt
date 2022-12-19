### 解题思路
解法一：
    用stack来反转

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
 import java.util.*;

class Solution {
    public ListNode reverseList(ListNode head) {
        if(head == null){
            return null;
        }
        Stack<ListNode> stack = new Stack<ListNode>();
        while(head != null){
            stack.push(head);
            head = head.next;
        } 
        ListNode node = stack.pop();
        ListNode pnode = node;
        while(!stack.isEmpty()){
            ListNode cnode = stack.pop();
            pnode.next = cnode;
            cnode.next = null;
            pnode = cnode;
        }
        return node;
    }
}
```