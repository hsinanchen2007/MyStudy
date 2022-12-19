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
        
        int c1 = 0;
        ListNode l1 = headA;
        while (l1 != null) {
            l1 = l1.next;
            ++c1;
        }

        int c2 = 0;
        ListNode l2 = headB;
        while (l2 != null) {
            l2 = l2.next;
            ++c2;
        }
        l1 = headA;
        l2 = headB;
        int count = Math.abs(c1-c2);
        if (c1 > c2) {
            
            while (count-- > 0) {
                l1 = l1.next;
            }
        } else if (c2 > c1) {
            
            while (count-- > 0) {
                l2 = l2.next;
            }
        }

        while( l1 != null && l2 != null) {
            if (l1 == l2) {
                return l1;
            }
            l1 = l1.next;
            l2 = l2.next;
        }
        return null;
    }
}
```