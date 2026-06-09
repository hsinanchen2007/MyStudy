### 解题思路
见代码

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
        ListNode ha = headA;
        ListNode hb = headB;
        while(ha != hb) {
            if(ha != null) {
                ha = ha.next;
            } else {
                ha = headB;
            }
            if(hb != null) {
                hb = hb.next;
            } else {
                hb = headA;
            }
        }
        return ha;
    }
}
```