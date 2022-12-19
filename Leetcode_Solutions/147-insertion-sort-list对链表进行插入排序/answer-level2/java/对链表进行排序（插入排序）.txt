### 解题思路
这份代码是我解决排序链表时写的。这里正好合适。

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
        ListNode p = head, q = head.next;
        p.next = null;
        while (q != null) {
            if (q.val >= p.val) {
                ListNode tmp = q;
                q = q.next;

                tmp.next = p.next;
                p = p.next = tmp;
                continue;
            }

            ListNode r = newHead;
            while (q.val > r.next.val) {
                r = r.next;
            }
            ListNode tmp = q;
            q = q.next;

            tmp.next = r.next;
            r.next = tmp;
        }
        return newHead.next;
    }
}
```