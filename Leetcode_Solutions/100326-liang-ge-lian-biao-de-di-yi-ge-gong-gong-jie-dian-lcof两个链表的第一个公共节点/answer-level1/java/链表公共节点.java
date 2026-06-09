### 解题思路
链表差，再同时走

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
        int lena=0;
        int lenb=0;
        ListNode a=headA;
        ListNode b=headB;
        while(a!=null){
            lena++;
            a=a.next;
        }
         while(b!=null){
            lenb++;
            b=b.next;
        }
        ListNode A=headA;
        ListNode B=headB;
        int cha=lena-lenb;
        int count=0;
        while(cha>0&&count<cha){
            A=A.next;
            count++;
        }
        while(cha<=0&&count>cha){
            B=B.next;
            count--;
        }
        while(A!=null&&B!=null){
            if(A==B)return A;
            A=A.next;
            B=B.next;
        }
        return null;
    }
}
```