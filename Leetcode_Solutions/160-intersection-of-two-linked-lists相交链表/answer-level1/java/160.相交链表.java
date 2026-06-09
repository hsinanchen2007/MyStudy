### 解题思路

执行用时 :1 ms, 在所有 Java 提交中击败了100.00%的用户

求长度找出差，长链推进差值个节点，然后同时向后遍历找到第一个相同结点。时间复杂度O(n),n 为长链长度。

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
        if(headA == null || headB == null) return null;
        ListNode la = headA;
        ListNode lb = headB;
        ListNode l = null;
        int ia = 0;
        int ib = 0;
        // 求长度
        while (la != null || lb != null) {
            if (la != null) {
                ia++;
                la = la.next;
            }
            if (lb != null) {
                ib++;
                lb = lb.next;
            }
        }
        
        la = headA;
        lb = headB;
        while (ia > ib){
            ia--;
            la = la.next;
        } 
        while (ib > ia){
            lb = lb.next;ib--;
            
        } 

        while (la != null && lb != null) {
            if (la == lb) {
                return la;
            }
            la = la.next;
            lb = lb.next;
        }
        return null;
    }
    
}
```