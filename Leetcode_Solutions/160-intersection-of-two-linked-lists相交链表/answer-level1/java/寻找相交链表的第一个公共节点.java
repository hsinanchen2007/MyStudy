### 解题思路
获取两个链表的长度，让长度较长的先走差值steps。之后一起一步一步走，如果节点相等则为第一个公共节点。
重点：第一个公共节点开始后续节点都一样，因此长度差值是一个突破点。
但是当前代码击败的用户数差强人意，需要继续分析下优化方案。

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
        int length1 = getLengthOfList(headA);
        int length2 = getLengthOfList(headB);
        int val = length1 - length2;
        ListNode p = null, q = null;
        if (val >= 0) {
            p = headA;
            q = headB;
        } else {
            p = headB;
            q = headA;
            val *= -1;
        }

        while (val > 0) {
            p = p.next;
            val--;
        }
        while (p != null && q != null && p != q) {
            p = p.next;
            q = q.next;
        }
        if (p == q) {
            return p;
        }
        return null;
    }
    public int getLengthOfList(ListNode head) {
        if (head == null) {
            return 0;
        }
        int count = 0;
        while (head != null) {
            count++;
            head = head.next;
        }
        return count;
    }
}
```