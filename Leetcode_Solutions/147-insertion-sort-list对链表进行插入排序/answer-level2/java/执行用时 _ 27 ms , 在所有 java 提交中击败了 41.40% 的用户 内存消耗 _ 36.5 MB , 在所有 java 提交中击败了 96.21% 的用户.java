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
    public ListNode insertionSortList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode newHead = new ListNode(0);
        newHead.next = head;
        ListNode p = head.next;
        head.next = null;

        while (p != null) {
            ListNode tmp = p;
            p = p.next;
            ListNode fast = newHead.next;
            ListNode slow = newHead;
            while (fast != null && fast.val < tmp.val) {
                fast = fast.next;
                slow = slow.next;
            }
            slow.next = tmp;
            tmp.next = fast;
        }
        return newHead.next;
    }
}
```