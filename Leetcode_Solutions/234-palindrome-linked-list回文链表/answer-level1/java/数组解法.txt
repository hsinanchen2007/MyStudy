### 解题思路
思路：采用格外空间的解法，首先遍历整个链表，确定额外数组的大小，然后再次遍历链表，装填数组，最后遍历一半数组，确定首尾回文相同。

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
    public boolean isPalindrome(ListNode head) {
        ListNode start = head;
        int num = 0;
        while (start != null) {
            ++num;
            start = start.next;
        }

        int[] values = new int[num];

        start = head;
        for (int i = 0; i < values.length; ++i) {
            values[i] = start.val;
            start = start.next;
        }

        start = head;
        for (int i = values.length - 1; i >= 0; --i) {
            if (start.val != values[i]) {
                return false;
            }
            start = start.next;
        }

        return true;
    }
}
```