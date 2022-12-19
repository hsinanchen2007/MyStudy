### 解题思路
此题思路就是添加一个前置指针进行双指针遍历即可。

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
    public ListNode deleteNode(ListNode head, int val) {
        if (head == null) {
            return null;
        }

        ListNode temp = head;
        ListNode prev = new ListNode(0);
        prev.next = temp;
        if (head.val == val) {
            return head.next;
        }

        while(temp != null && temp.val != val) {
            prev = temp;
            temp = temp.next;
        }

        if (temp.next == null) {
            prev.next = null;
        } else {
            prev.next = temp.next;
        }

        return head;

    }
}
```