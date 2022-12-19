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
    public ListNode reverseList(ListNode head) {
        ListNode p = head, pre = null, after = null;
        while (p != null) {
            after = p.next;
            p.next = pre;
            pre = p;
            p = after;
        }
        return pre;
    }
}
```

