### 解题思路
1. 遍历节点，第一个值大于等于 x 的节点为插入锚点，用 anchor 记录此节点的前一个节点
2. 遍历的过程中也使用 prev, head 两个节点同步遍历
3. 当 anchor 初始化后，小于 x 的值，需要插入到 anchor 的位置

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
    public ListNode partition(ListNode head, int x) {
         if (head == null || head.next == null) return head;

        ListNode newHead = new ListNode(0);
        newHead.next = head;
        ListNode anchor = null, prev = newHead;

        while (head != null) {
            if (head.val < x && anchor == null) {
                prev = prev.next;
                head = head.next;
                continue;
            }

            if (anchor == null) {
                anchor = prev;
                prev = prev.next;
                head = head.next;
                continue;
            }

            if (head.val >= x) {
                prev = prev.next;
                head = head.next;
                continue;
            }

            prev.next = head.next;
            head.next = anchor.next;
            anchor.next = head;
            anchor = anchor.next;
            head = prev.next;
        }

        return newHead.next;
    }
}
```