### 解题思路
1. 将原链表拆分成两个链表 left 和 right
2. left 为 [0, m - 1] 部分，尾插
3. right 为 [m, n] 部分，头插
4. 最后将 left、right 和链表剩下部分拼接返回

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
        if (head == null || head.next == null) return head;

        ListNode left = new ListNode(0);
        ListNode p1 = left;
        ListNode right = new ListNode(0);
        ListNode p2 = null;

        int k = 1;
        for (; head != null && k <= n; k++) {
            if (k < m) {
                p1.next = head;
                p1 = p1.next;
                head = head.next;
            } else if (k >=m && k <=n) {
                ListNode tmp = head;
                head = head.next;
                tmp.next = right.next;
                right.next = tmp;
                if (p2 == null) {
                    p2 = tmp;
                }
            }
        }

        p1.next = right.next;
        if (p2 != null) p2.next = head;

        return left.next;
    }
}
```