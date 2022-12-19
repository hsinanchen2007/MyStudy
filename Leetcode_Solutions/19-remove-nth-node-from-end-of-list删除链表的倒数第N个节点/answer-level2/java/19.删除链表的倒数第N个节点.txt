### 解题思路
双指针遍历加个头节点，O(n)

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
        // 加个头节点省事
        ListNode node = new ListNode(0);
        node.next = head;
        ListNode p = node;
        ListNode q = node;
        // q 移动 n 个提前量
        while (n-- > 0 && q.next != null) q = q.next;
        // 一起移动
        while (q.next != null) {
            p = p.next;
            q = q.next;
        }
        p.next = p.next.next;
        return node.next;
    }
}
```