### 解题思路
注意两个边界和空指针问题即可。

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
    public ListNode deleteNode(ListNode head, int val) {
        ListNode cur = head;
        if (head.val == val) {
            return head.next;
        }
        while (cur.next != null) {
            if (cur.next.val == val) {
                break;
            }
            cur = cur.next;
        }
        if (cur.next != null) {
            cur.next = cur.next.next;
        }
        return head;
    }
}
```