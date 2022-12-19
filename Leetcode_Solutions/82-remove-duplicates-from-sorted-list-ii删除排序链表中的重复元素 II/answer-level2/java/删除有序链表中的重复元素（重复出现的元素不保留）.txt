### 解题思路
这道题目重点是只要重复出现过，则该值不会出现在最终的链表中，即头节点会改变。

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
    public ListNode deleteDuplicates(ListNode head) {
        ListNode newHead = new ListNode(0);
        ListNode p = head, q = newHead;
        while (p != null && p.next != null) {
            if (p.val != p.next.val) {
                q = q.next = p;
                p = p.next;
                continue;
            }
            while (p != null && p.next != null && p.val == p.next.val) {
                p = p.next;
            }
            if (p != null && p.next != null) {
                p = p.next;
                continue;
            }
            p = p.next;
        }
        if (p != null) {
            q.next = p;
        } else {
            q.next = null;
        }
        return newHead.next;
    }
}
```