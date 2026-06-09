### 解题思路
当遇到重复节点时，让指针指向下一个值不一样的节点继续处理即可。

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
        if (head == null || head.next == null) {
            return head;
        }

        ListNode newHead = new ListNode(0);
        ListNode p = head, q = newHead;
        while (p != null && p.next != null) {
            q = q.next = p;
            if (p.val != p.next.val) {
                p = p.next;
                continue;
            }
            while (p != null && p.next != null && p.val == p.next.val) {
                p = p.next;
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