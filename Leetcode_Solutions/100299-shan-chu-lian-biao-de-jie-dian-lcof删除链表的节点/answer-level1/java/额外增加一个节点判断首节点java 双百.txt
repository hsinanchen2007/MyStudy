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
    public ListNode deleteNode(ListNode head, int val) {
        if (head == null) {
            return null;
        }
        ListNode dummy = new ListNode (0);
        dummy.next = head;
        ListNode r = dummy;
        ListNode p = head;
        ListNode q = head.next;
        while (p != null) {
            if (p.val == val) {
                r.next = q;
                break;
            }else {
                r = p;
                p = q;
                if (q != null) {
                    q = q.next;
                }
            }
        }
        return dummy.next;
    }
}
```