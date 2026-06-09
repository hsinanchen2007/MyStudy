### 解题思路
快慢指针

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
    public boolean hasCycle(ListNode head) {
        // 快慢指针，有环，块的一定会追上慢的
        ListNode fast = head;
        ListNode slow = head;

        while (null != fast && null != fast.next && null != slow) {
            fast = fast.next.next;
            if (fast==slow) {
                return true;
            }
            slow = slow.next;
        }

        return false;
    }
}
```