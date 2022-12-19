### 解题思路

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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if (l2 == null && l1 != null) {
            return l1;
        } 
        if (l1 == null && l2 != null) {
            return l2;
        }
        if (l1 == null && l2 == null) {
            return null;
        }
        int sum = l1.val + l2.val;
        int pre = 0;
        if (sum > 9) {
            pre = 1;
            sum = sum - 10;
        }
        ListNode res = new ListNode(sum);
        ListNode move = res;
        l1 = l1.next;
        l2 = l2.next;
        while (l1 != null && l2 != null) {
            sum = l1.val + l2.val + pre;
            if (sum > 9) {
                pre = 1;
                sum = sum - 10;
            } else {
                pre = 0;
            }
            move.next = new ListNode(sum);
            move = move.next;
            l1 = l1.next;
            l2 = l2.next;
        }
        while (l1 != null) {
            sum = l1.val + pre;
            if (sum > 9) {
                pre = 1;
                sum = sum - 10;
            } else {
                pre = 0;
            }
            move.next = new ListNode(sum);
            move = move.next;
            l1 = l1.next;
        }
        while (l2 != null) {
            sum = l2.val + pre;
            if (sum > 9) {
                pre = 1;
                sum = sum - 10;
            } else {
                pre = 0;
            }
            move.next = new ListNode(sum);
            move = move.next;
            l2 = l2.next;
        }
        if (pre == 1) {
            move.next = new ListNode(pre);
        }
        return res;
    }

}
```