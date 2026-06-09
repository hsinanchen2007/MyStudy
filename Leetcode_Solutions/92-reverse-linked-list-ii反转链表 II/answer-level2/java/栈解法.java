创建一个栈，将要连接的部分压入栈，然后弹出，连接前后，即得解。
（解法可能慢了点，但也是一种思路）
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
    public ListNode reverseBetween(ListNode head, int m, int n) {
        if (head == null) {return null;}
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode pointer = dummy;
        int count = 0;
        ListNode reverseHead = new ListNode(-1), reverseLast = new ListNode(-1);
        Stack<ListNode> reverseStack = new Stack<>();
        while (pointer != null) {
            if (count == m - 1) {
                reverseHead = pointer;
            }
            // 将要翻转的部分入栈
            if (count >= m && count <= n) {
                reverseStack.push(pointer);
            }
            if (count == n + 1) {
                reverseLast = pointer;
            }
            pointer = pointer.next;
            count++;
        }
        // 连接之前的一部分
        while (!reverseStack.empty()) {
            reverseHead.next = reverseStack.pop();
            reverseHead = reverseHead.next;
        }
        // 连接之后的一部分
        if (count != n && count != n+1) {
            reverseHead.next = reverseLast;
        }
        else {
            reverseHead.next = null;
        }
        return dummy.next;
    }
}
```
