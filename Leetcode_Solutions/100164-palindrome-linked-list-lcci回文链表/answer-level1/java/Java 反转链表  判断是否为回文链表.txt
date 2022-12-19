### 解题思路
链表逆序！！！然后都从head开始遍历，不想等则非回文。

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
    public boolean isPalindrome(ListNode head) {
        if (head == null || head.next == null) {
            return true;
        }
        ListNode newHead = new ListNode(0);
        ListNode p = head;
        // 将链表逆序，生成新链表newHead（带头节点的）
        while (p != null) {
            ListNode tmp = new ListNode(p.val);
            // 头插法
            tmp.next = newHead.next;
            newHead.next = tmp;

            p = p.next;
        }
        ListNode q = newHead.next;
        p = head;
        while (p != null) {
            if (p.val != q.val) {
                return false;
            }
            p = p.next;
            q = q.next;
        }
        return true;
    }
}
```