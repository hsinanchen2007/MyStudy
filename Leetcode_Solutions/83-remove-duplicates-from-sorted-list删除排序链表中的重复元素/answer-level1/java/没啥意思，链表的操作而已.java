### 解题思路
没啥意思，链表的操作而已

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

        ListNode slow = head, fast = head.next;
        while (fast != null) {
            if(slow.val == fast.val) {
                fast = fast.next;
                continue;
            }
            slow.next = fast;
            slow = slow.next;
            fast = fast.next;
        }
        slow.next = null;
        return head;
    }
}
```