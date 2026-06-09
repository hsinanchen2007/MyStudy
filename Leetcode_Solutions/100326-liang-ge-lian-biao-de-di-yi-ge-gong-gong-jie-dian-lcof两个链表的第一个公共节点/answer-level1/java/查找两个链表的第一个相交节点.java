### 解题思路
利用a+b+相交=b+a+相交即可

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
        ListNode nodeA = headA;
        ListNode nodeB = headB;
        while(nodeA!=nodeB){
            nodeA = nodeA==null?headB:nodeA.next;
            nodeB = nodeB==null?headA:nodeB.next;
        }
        return nodeA;
    }
}
```