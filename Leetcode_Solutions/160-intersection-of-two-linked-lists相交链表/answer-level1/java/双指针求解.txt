### 解题思路
此处撰写解题思路

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
        
        ListNode lA = headA;
        ListNode lB = headB;

        while (lA != lB) {

            if (lA != null) {
                lA = lA.next;
            } else {
                lA = headB;
            }

            if (lB != null) {
                lB = lB.next;
            } else {
                lB = headA;
            }
        }

        if (lA == lB) {
            return lA;
        }

        return null;

    }

}
```