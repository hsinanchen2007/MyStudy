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

        ListNode p = head, q = head;
        for (int i = 0; i < k; i++)
            q = q.next;

        while (q != null) {
            p = p.next;
            q = q.next;
        }

        return p.val;
    }
}
```