### 解题思路
快慢指针

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
    public ListNode middleNode(ListNode head) {
        if (head == null) {
            return null;
        }

        ListNode p = head, q = head.next;
        while (q != null && q.next != null) {
            p = p.next;
            q = q.next.next;
        }
        if (q != null) {
            return p.next;
        }

        return p;
    }
}
```