### 解题思路


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
        int aLen = 0 ;
        int bLen = 0 ;
        ListNode newAHead = headA ;
        ListNode newBHead = headB ;
        while(newAHead != null) {
            newAHead = newAHead.next ;
            aLen ++ ;
        }
        while(newBHead != null) {
            newBHead = newBHead.next ;
            bLen ++ ;
        }

        boolean isALonger = aLen > bLen ;
        ListNode longerNode = isALonger==true ?  headA : headB ;
        ListNode shortNode = isALonger==true ?  headB : headA ;
        int gap = Math.abs(aLen - bLen);
        while (longerNode != null) {
            if (gap > 0) {
                longerNode = longerNode.next ;
                gap -- ;
            }else{
                if (longerNode == shortNode)
                    return longerNode ;
                else{
                    longerNode = longerNode.next ;
                    shortNode = shortNode.next ;
                }
            }
        }
        return null ;

    }
}
```