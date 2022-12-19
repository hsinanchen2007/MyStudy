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
    public ListNode oddEvenList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode first = head;
        ListNode second = head.next;
        ListNode tail = head.next;


        ListNode tmp1, tmp2;
        while (second != null && second.next != null) {
            tmp1 = first.next.next;
            first.next = tmp1;
            first = tmp1;
            tmp2 = second.next.next;
            second.next = tmp2;
            second = tmp2;
        }

        first.next = tail;
        return head;
    }
}
```