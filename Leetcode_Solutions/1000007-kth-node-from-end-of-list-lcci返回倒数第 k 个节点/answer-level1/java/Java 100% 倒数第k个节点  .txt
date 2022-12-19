### 解题思路
快慢指针，一个指针先走k步，然后一起走，走到null时，后走的指针对应节点即倒数dik个节点。

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
        if (head == null) {
            return -1;
        }

        ListNode p = head;
        while (p != null && k > 0) {
            p = p.next;
            k--;
        }
        if (p == null && k == 0) {
            return  head.val;
        }
        if (p == null && k > 0) {
            return -1;
        }
        ListNode q = head;
        while (p != null) {
            p = p.next;
            q = q.next;
        }

        return q.val;
    }
}
```