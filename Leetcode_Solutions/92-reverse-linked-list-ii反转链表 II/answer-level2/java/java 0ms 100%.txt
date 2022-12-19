### 解题思路
首先找到要反转的区间，再将这个区间里的node反转，接上原链表
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
    public ListNode reverseBetween(ListNode head, int m, int n) {

        ListNode dummyHead = new ListNode(-1);
        dummyHead.next = head;

        ListNode pre = dummyHead;
        ListNode start = head;
        ListNode end = head;
        int i = 1;
        while (i < m || i < n) {
            if (i < m) {
                start = start.next;
                pre = pre.next;
            }
            end = end.next;
            i++;
        }
        ListNode next = end.next;
        reverse(start, next);
        pre.next = end;
        start.next = next;

        return dummyHead.next;
    }

    private void reverse(ListNode start, ListNode end) {
        ListNode pre = null;
        ListNode cur = start;
        ListNode next;
        while (cur != end) {
            next = cur.next;
            cur.next = pre;
            pre = cur;
            cur = next;
        }
    }
}
```