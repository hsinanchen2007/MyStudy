### 解题思路
快慢指针
如果是奇数个，直接返回慢指针
如果是偶数个，慢指针再走一步，返回即可

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
        //bad-case
        if (head == null || head.next == null) {
            return head;
        }
        //快慢指针
        //记录快指针走的步数
        ListNode slow = head;
        ListNode fast = head;

        //快慢指针同步走
        while (fast.next != null && fast.next.next != null) {
            fast = fast.next.next;
            slow = slow.next;
        } 

        if (fast.next != null && fast.next.next == null) {
            slow = slow.next;
        }

        return slow;
    }
}
```