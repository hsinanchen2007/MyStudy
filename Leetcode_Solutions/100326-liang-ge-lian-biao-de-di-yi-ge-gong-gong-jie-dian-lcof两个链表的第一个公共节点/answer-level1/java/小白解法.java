### 解题思路
知乎大佬写的题解，简单易懂
https://zhuanlan.zhihu.com/p/105940783

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
        if(headA==null||headB==null){
            return null;
        }
        int lenA=0;
        int lenB=0;
        ListNode a=headA;
        ListNode b=headB;
        while(a!=null){
            lenA++;
            a=a.next;
        }
        while(b!=null){
            lenB++;
            b=b.next;
        }
        if(lenA>lenB){
            int go=lenA-lenB;
            while(go!=0){
                go--;
                headA=headA.next;
            }
        }else{
            int go=lenB-lenA;
            while(go!=0){
                go--;
                headB=headB.next;
            }
        }
        while(headA!=headB){
            headA=headA.next;
            headB=headB.next;
        }
        return headA;
    }
}
```