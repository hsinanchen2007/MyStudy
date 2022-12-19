### 解题思路
我偏偏要改值

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
    public ListNode swapPairs(ListNode head) {
        if (head == null) return null;
        int a = 0;
        ListNode res = head;
        while(head.next != null) {
            if (a % 2 == 0) {
                int valu = head.val;
                head.val = head.next.val;
                head.next.val = valu;
                head = head.next;
            } else {
                head = head.next;
            }
            a++;
        }
        return res;
    }
}
```