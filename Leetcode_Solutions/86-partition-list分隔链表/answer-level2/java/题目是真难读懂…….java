> 思路：就是将大于目标的节点取出来，然后与不含这些节点的原链表拼接起来。

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
    ListNode p1 = new ListNode(0),
            p2 = new ListNode(0),
            p3 = p1,
            p4 = p2;
    p2.next = head;
    
    while (p2.next != null) {
      if (p2.next.val < x) {
        p1.next = p2.next;
        p1 = p1.next;
        p2.next = p2.next.next;
        p1.next = null;     
      } else {
        p2 = p2.next;
      }
    }
    p1.next = p4.next;
    return p3.next;
  }
}
```