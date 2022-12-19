### 解题思路
一次循环解决

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
        ListNode r = head;
        while (head.next != null) {
            if (k != 1) {
                k--;
            } else {
                r = r.next;
            }
            head = head.next;
        }
        return r;
    }
}
```