### 解题思路

5个while双100

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
        int lenA = 0;
        int lenB = 0;
        ListNode nodeA = headA;
        ListNode nodeB = headB;
        while (nodeA != null) {
            lenA ++;
            nodeA = nodeA.next;
        }
        while (nodeB != null) {
            lenB ++;
            nodeB = nodeB.next;
        }
        nodeA = headA;
        nodeB = headB;
        while (lenA < lenB) {
            nodeB = nodeB.next;
            lenB --;
        }
        while (lenA > lenB) {
            nodeA = nodeA.next;
            lenA --;
        }
        while (nodeA != nodeB) {
            nodeA = nodeA.next;
            nodeB = nodeB.next;
        }
        return nodeA;
    }
}
```