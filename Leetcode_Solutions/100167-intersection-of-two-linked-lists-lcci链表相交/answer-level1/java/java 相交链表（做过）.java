### 解题思路
1.a+b=b+a
2.长度相等时，有交点，到交点时结束，没有交点到null时结束
3.长度不相等时，a+b=b+a，有交点，到交点结束，没有交点，到null处结束


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
        if(headA == null || headB == null ) return null;
        ListNode hA = headA, hB =headB;
        while(hA!=hB){
            hA = hA==null?headB:hA.next;
            hB = hB==null?headA:hB.next;
        }

        return hA;
    }
}
```