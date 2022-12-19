### 解题思路
可以参考判断单链表是否有环的操作。
定义两个指针，快指针和慢指针。
慢指针每次走一步，快指针每次走两步。
当快指针走了链表尾的时候，慢指针走到中间节点，需要注意边界条件的判断。

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
        if (head == null || head.next == null) {
            return head;
        }
        ListNode slow = head;
        ListNode fast = head.next;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        if (fast == null) {
            return slow;
        }
        return slow.next;
    }
}
```