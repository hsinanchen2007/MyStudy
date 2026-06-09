```
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
        if(headA==null || headB==null) return null;
        ListNode curA = headA,curB = headB;
        int lenA=0,lenB=0;
        while(curA!=null){
            lenA++;
            curA=curA.next;
        }
        while(curB!=null){
            lenB++;
            curB=curB.next;
        }
        int diff = Math.abs(lenA-lenB);
        if(lenA<lenB){
            curA=headB;
            curB=headA;
        }else{
            curA=headA;
            curB=headB;
        }
        while(diff-->0) curA=curA.next;
        while(curA!=curB){  // 根据元素值匹配的话，第一个例子返回值是1
            curA=curA.next;
            curB=curB.next;
        }
        return curA;
    }
}
```
