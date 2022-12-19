### 解题思路
            carry = (x + y + carry) > 9 ? 1 : 0;

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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
            ListNode q = l1;
        ListNode p = l2;
        int carry = 0;
        ListNode result = new ListNode(0);
        ListNode current = result;
        while (q != null || p != null) {
            int x = q == null ? 0 : q.val;
            int y = p == null ? 0 : p.val;
            current.next = new ListNode((x + y + carry) % 10);
            current = current.next;

            carry = (x + y + carry) > 9 ? 1 : 0;
            if (q != null) {
                q = q.next;
            }
            if (p != null) {
                p = p.next;
            }
        }
        if (carry == 1) {
            current.next = new ListNode(1);
        }
        return result.next;
    }
}
```