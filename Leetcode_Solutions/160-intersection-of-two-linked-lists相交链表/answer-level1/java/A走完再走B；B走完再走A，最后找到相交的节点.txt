### 解题思路
//思想，链表A走到头了，再从B的头结点开始
        //链表B走到头了，再从A的头结点开始,他们两总会相交于一点
   最后把这个公共节点返回，就找到了相交的节点

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
        //思想，链表A走到头了，再从B的头结点开始
        //链表B走到头了，再从A的头结点开始,他们两总会相交于一点
        ListNode A=headA;
        ListNode B=headB;
        while(A!=B){
            A= (A==null)?headB:A.next;
            B= (B==null)?headA:B.next;
        }
        return B;
    }
}
```