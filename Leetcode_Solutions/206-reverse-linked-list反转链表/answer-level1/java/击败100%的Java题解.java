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
        ListNode dummy = new ListNode(0);
        ListNode prev = null;
        while(head != null) {
          ListNode next = head.next;
          head.next = dummy.next;
          dummy.next = head;
          head = next;
        }
        return dummy.next;

    }
}
```