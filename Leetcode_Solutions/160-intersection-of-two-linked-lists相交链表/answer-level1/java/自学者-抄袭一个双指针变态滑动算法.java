### 解题思路
* 脑瓜不太够用

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
        if(headA == null || headB == null) {
            return null;
        }
        ListNode pA = headA;
        ListNode pB = headB;
        while(pA != pB) {
            pA = pA.next;
            pB = pB.next;
            if(pA == null && pB == null) {
                return null;
            }
            if(pA == null) {
                pA = headB;
            }
            if(pB == null) {
                pB = headA;
            }
        }
        return pA;

    }
}
```