### 解题思路
我直接swap的，行不行啊

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
    public ListNode insertionSortList(ListNode head) {

        ListNode c = head;
        while (c != null) {
            // 外层i
            ListNode cur = c;
            while (cur.next != null) {
                // 内层j
                ListNode next = cur.next;
                if (next.val < c.val) {
                    int tmp = c.val;
                    c.val = next.val;
                    next.val = tmp;
                }
                cur = next;
            }
            c = c.next;
        }
        return head;
    }
}
```