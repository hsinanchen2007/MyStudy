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
        ListNode curA = headA;
        ListNode curB = headB;
        while(curA!=null){
            curB = headB;
            while(curB!=null){
                if(curA==curB){
                    return curB; 
                }
                else
                    curB = curB.next;
            }
            curA = curA.next;
        }
        return null;
    }
}




```