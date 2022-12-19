> 记录起始的节点和结束的节点，最后重新链接节点，缺点是定义的值比较多

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
    if (head == null || head.next == null || m == n) return head;
    ListNode p1 = new ListNode(0), p2 = p1, start, end, tmp1 = null, tmp2 = null;
    p1.next = head;
    int idx = 0;
    while(++idx < m) p1 = p1.next;
    start = p1;
    end = p1.next;
    while(true) {
      tmp2 = p1.next;
      p1.next = tmp1;
      tmp1 = p1;
      if (idx++ == n + 1) {
        end.next = tmp2;
        start.next = tmp1;
        break;
      }
      p1 = tmp2;
    }
    return p2.next;
  }
}
```