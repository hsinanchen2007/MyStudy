### 解题思路
此处撰写解题思路

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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode fast = head;
        ListNode slow = fast;
        ListNode pre = slow;
        // head 赋值是一步
        for (int i = 0; i < n-1; i++) {
            fast = fast.next;
        }
        while (fast.next != null) {
            pre = slow;
            slow = slow.next;
            fast = fast.next;
        }
        // 如果是删除头节点，则直接返回头节点的下一个节点
        if (pre == slow) {
            return head.next;
        }
        pre.next = slow.next;
        return head;
    }
}
```