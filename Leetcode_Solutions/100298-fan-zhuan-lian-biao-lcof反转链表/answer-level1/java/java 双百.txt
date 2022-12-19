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
    public ListNode reverseList(ListNode head) {
        ListNode tail = null;
        if (head == null) {
            return head;
        }
        ListNode next = head.next;
        while (next != null) {
            head.next = tail;
            tail = head;
            head = next;
            next = next.next;
        }
        head.next = tail;
        return head;
    }
}
```