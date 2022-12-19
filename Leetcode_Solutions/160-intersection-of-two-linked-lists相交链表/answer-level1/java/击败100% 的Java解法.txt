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
        ListNode currentA = headA;
        ListNode currentB = headB;
        int lenA = 0;
        while(currentA != null) {
            currentA = currentA.next;
            ++lenA;
        }
        int lenB = 0;
        while(currentB != null) {
            currentB = currentB.next;
            ++lenB;
        }
        ListNode longerNode = (lenA > lenB ? headA : headB);
        ListNode shorterNode = (longerNode == headA ? headB : headA);
        for (int i = 0; i < Math.abs(lenA - lenB); ++i) {
            longerNode = longerNode.next;
        }
        while(longerNode != shorterNode) {
            longerNode = longerNode.next;
            shorterNode = shorterNode.next;
        }
        return longerNode;
        
    }
}
```