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
        if(headA==null&&headB==null)
            return null;
        ListNode nodeA=headA;
        ListNode nodeB=headB;
        while(nodeA!=nodeB)
        {
            nodeA=nodeA==null? headB:nodeA.next;
            nodeB=nodeB==null? headA:nodeB.next;
        }
        return nodeA;
    }
}
```