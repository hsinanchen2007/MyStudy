### 解题思路
找到翻转区间的前一个pre，和翻转区间后一个right用来拼接用,
然后leftbound, rightbound按照翻转链表的方式来，

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
        if (head == null || head.next == null || m == n) {
            return head;
        }
        ListNode tummy = new ListNode(0);
        tummy.next = head;
        ListNode pre = tummy;
        for (int i = 1; i < m; i++) {
            pre = pre.next;
        }
        ListNode rightBound = head;
        for (int i = 0; i < n - 1; i++) {
            rightBound = rightBound.next;
        }
        ListNode right = rightBound.next;
        ListNode leftBound = pre.next;
        ListNode left = pre.next;

        ListNode curr = leftBound.next;

        while (curr != rightBound) {
            ListNode tmp = curr.next;
            curr.next = leftBound;
            leftBound = curr;
            curr = tmp;
        }
        left.next = right;
        pre.next = rightBound;
        rightBound.next = leftBound;
        return tummy.next;
    }
}
```