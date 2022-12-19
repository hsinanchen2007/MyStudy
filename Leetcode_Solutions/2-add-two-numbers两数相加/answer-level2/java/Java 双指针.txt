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
        ListNode Dummy = new ListNode(0);
        ListNode head = Dummy;
        int carry = 0;
        while (l1 != null || l2 != null) {
            int c1 = l1 == null ? 0 : l1.val;
            int c2 = l2 == null ? 0 : l2.val;
            int sum = c1 + c2 + carry;
            head.next = new ListNode(sum % 10);
            head = head.next;
            carry = sum / 10;
            if (l1 != null) l1 = l1.next;
            if (l2 != null) l2 = l2.next;
        }
        if (carry > 0) head.next = new ListNode(1);
        return Dummy.next;
    }
}
```