### 解题思路
1. 判断是否有环
2. 环中节点个数
3. 快慢指针，快指针先走环中节点个数步

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
        ListNode p = hasCycle(head);
        if (p == null) {
            return null;
        }

        int count = 1;
        ListNode q = p.next;
        while (q != p) {
            count++;
            q = q.next;
        }
        q = head;
        while (count > 0) {
            q = q.next;
            count--;
        }

        p = head;
        while (p != q) {
            p = p.next;
            q = q.next;
        }

        return p;
    }

    public ListNode hasCycle(ListNode head) {
        if (head == null || head.next == null) {
            return null;
        }

        ListNode p = head, q = head.next;
        while (p != null && q != null) {
            if (p == q) {
                return p;
            }

            if (q.next == null) {
                return null;
            }
            p = p.next;
            q = q.next.next;
        }

        return null;
    }
}
```