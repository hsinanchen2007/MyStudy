### 解题思路
此处撰写解题思路

### 代码

```java
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode p = hasLoop(head);
        if (p == null) {
            return null;
        }

        // LoopLength
        int count = 1;
        ListNode q = p.next;
        while (q != p) {
            q = q.next;
            count++;
        }

        // getKthFromTail
        return getKthFromTail(head, count);
    }

    public ListNode getKthFromTail(ListNode head, int count) {
        ListNode p = head;
        while (count > 0) {
            p = p.next;
            count--;
        }

        ListNode q = head;
        while (p != q) {
            p = p.next;
            q = q.next;
        }
        return q;
    }

    public ListNode hasLoop(ListNode head) {
        if (head == null) {
            return null;
        }

        ListNode p = head, q = head.next;
        while (p != null && q != null) {
            if (p == q) {
                return p;
            }
            if (q.next != null) {
                q = q.next.next;
            } else {
                return null;
            }
            p = p.next;
        }
        return null;
    }
}
```