### 解题思路
此处撰写解题思路

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
    public ListNode swapPairs(ListNode head) {
        if (null == head || null == head.next) {
            return head;
        }
        ListNode pre = new ListNode(0);
        ListNode fast = head.next;
        ListNode slow = head;
        ListNode res = pre;
        while (fast != null) {
            ListNode next = fast.next;
            pre.next = fast;
            fast.next = slow;
            slow.next = null;
            pre = slow;
            if (null != next) {
                slow = next;
                fast = slow.next;
            }
        }
        if (null != slow) {
            pre.next = slow;
            slow.next = null;
        }
        return res.next;
    }
}
```