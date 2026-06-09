### 解题思路
如果相交，则交点之后所有节点一样！！！
所以节点多的先走差值步数，然后一起走！！！

### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        int length1 = getLength(headA);
        int length2 = getLength(headB);
        ListNode p = headA, q = headB;
        int val = Math.abs(length1 - length2);
        if (length2 > length1) {
            p = headB;
            q = headA;
        }
        while (p != null && val > 0) {
            val--;
            p = p.next;
        }
        while (p != q) {
            p = p.next;
            q = q.next;
        }

        return p;
    }

    private int getLength(ListNode head) {
        int count = 0;
        while (head !=  null) {
            head = head.next;
            count++;
        }
        return count;
    }
}
```