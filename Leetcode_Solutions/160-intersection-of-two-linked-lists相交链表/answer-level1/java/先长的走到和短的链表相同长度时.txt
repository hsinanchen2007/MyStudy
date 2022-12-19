### 解题思路
先求出链表长度，先较长的链表走到和较短的链表相同长度时，同时循环链表，如果有相同的节点，那么返回否则返回null；

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
        ListNode a  = headA;
        ListNode b = headB;
        int countA=0;
        int countB=0;
        while(a!=null){
            countA++;
            a = a.next;
        }
        while(b!=null){
            countB++;
            b = b.next;
        }
        a = headA;
        b = headB;
        if(countA>countB){
            for(int i=0;i<countA-countB;i++){
                a = a!=null?a.next:null;
            }
        }else{
            for(int i=0;i<countB-countA;i++){
                b = b!=null?b.next:null;
            }
        }
        while(a!=null||b!=null){
            if(a==b){
                return a;
            }
            a = a.next;
            b = b.next;
        }
        return null;
    }
}
```