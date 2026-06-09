Java 击败 100% 解法：

``` java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode helper = new ListNode(0);
        helper.next = head;
        ListNode p = head, q = helper;
        while (p != null && p.next != null) {
            q.next = p.next;
            p.next = q.next.next;
            q.next.next = p;
            q = p;
            p = p.next;
        }
        return helper.next;
    }
}
```