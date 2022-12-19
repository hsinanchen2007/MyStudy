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
    public int kthToLast(ListNode head, int k) {
        for (; ; ) {
            ListNode cur = head;
            for (int i = 0; i < k; i++) {
                cur = cur.next;
            }
            if (cur == null) {
                return head.val;
            }
            head = head.next;
        }
    }
}
```