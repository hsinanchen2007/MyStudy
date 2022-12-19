### 解题思路
i先走k步，然后i，j同步走直到i到达终点

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
    public ListNode getKthFromEnd(ListNode head, int k) {
        ListNode i = head;
        ListNode j = head;
        while (i != null && k > 0) {
            i = i.next;
            k--;
        }
        while (i != null) {
            i = i.next;
            j = j.next;
        }
        return j;
    }
}
```