### 解题思路
先判断一下是否会**相交**，两个指针一直指到空，看最后是否相等。并**计数**。
如果A长度为10，B长度为7。那就先让A走3次。**即为让长的先走一截。**然后一起一格一格地走。
本质上和官方题解双指针是一样的，但**更直觉**一点。

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
        if(headA==null||headB==null)return null;
        int countA=0,countB=0,k=0;
        ListNode A=headA,B=headB;
        while(A.next!=null){
            A=A.next;
            countA++;
        }
        while(B.next!=null){
            B=B.next;
            countB++;
        }
        if(A!=B)return null;
        A=headA;B=headB;
        if(countA<=countB){
            k=countB-countA;
            for(int t=0;t<k;t++)B=B.next;
            while(A!=B){
                A=A.next;B=B.next;
            }
            return A;
        }else{
            k=countA-countB;
            for(int t=0;t<k;t++)A=A.next;
            while(A!=B){
                A=A.next;B=B.next;
            }
            return B;
        }
        
    }
}
```